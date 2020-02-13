#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <map>

std::map<std::string, long> decode = {
    {"one", 1},
    {"two", 2},
    {"three",3},
    {"four",4},
    {"five", 5},
    {"six", 6},
    {"seven", 7},
    {"eight", 8},
    {"nine", 9},
    {"ten", 10},
    {"eleven", 11},
    {"twelve", 12},
    {"thirteen", 13},
    {"fourteen", 14},
    {"fifteen", 15},
    {"sixteen", 16},
    {"seventeen", 17},
    {"eighteen", 18},
    {"nineteen", 19},
    {"twenty", 20},
    {"thirty", 30},
    {"forty", 40},
    {"fifty", 50},
    {"sixty", 60},
    {"seventy", 70},
    {"eighty", 80},
    {"ninety", 90}
};

long parse_tens_and_ones(std::string num){
    size_t hifen_pos = num.find('-');
    if (hifen_pos == std::string::npos){
        return decode[num];
    }
    return decode[num.substr(0, hifen_pos)] + decode[num.substr(hifen_pos+1)];
}

long parse_hundreds_and_tens(std::vector<std::string>::iterator num_start,
                             std::vector<std::string>::iterator num_end){
    auto hundred_pos = std::find(num_start, num_end, "hundred");
    //no hundred word, its just a tens and ones number
    if (hundred_pos == num_end){
        return parse_tens_and_ones(*num_start);
    }
    //hundred is the last word
    if(std::distance(hundred_pos, num_end) == 1){
        return 100*decode[*(hundred_pos-1)];
    }
    //words before and after hundred
    return 100*decode[*(hundred_pos-1)] + parse_tens_and_ones(*(hundred_pos+1));
}

long parse_int(std::string number) {

    if(number == "zero"){
        return 0;
    }

    if(number == "one million"){
        return 1000000;
    }

    std::istringstream number_stream(number);
    std::vector<std::string> words;
    std::copy(std::istream_iterator<std::string>(number_stream),
              std::istream_iterator<std::string>(),
              back_inserter(words));

    std::vector<std::string>::iterator pos;
    while((pos = find(words.begin(), words.end(), "and")) != words.end()){
        words.erase(pos);
    }

    auto thousand_pos = std::find(words.begin(), words.end(), "thousand");

    //This number is >= 1000
    if(thousand_pos != words.end()){
        long sum = parse_hundreds_and_tens(words.begin(), thousand_pos)*1000;
        if (std::distance(thousand_pos, words.end()) != 1){
            sum += parse_hundreds_and_tens(thousand_pos+1, words.end());
        }
        return sum;
    }
    
    return parse_hundreds_and_tens(words.begin(), words.end());
}

int main(){
    std::cout << parse_int("one") << std::endl;
    std::cout << parse_int("twenty-three") << std::endl;
    std::cout << parse_int("ninety-nine") << std::endl;
    std::cout << parse_int("sixty") << std::endl;

    std::cout << parse_int("seven hundred eighty-three thousand nine hundred and nineteen") << std::endl;
}