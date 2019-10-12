#include <string>
#include <iostream>

std::string sum_strings(std::string a, std::string b) {

    std::string ret;
    //a is always the longest string
    if(a.length() < b.length()) std::swap(a,b);

    auto it1 = a.rbegin();
    auto it2 = b.rbegin();

    int carry = 0;

    while (it1 != a.rend()){
        int n1 = 0, n2 = 0;

        n1 = *it1++ - 0x30;
        if (it2 != b.rend()){
            n2 = *it2++ - 0x30;
        }

        int res = (n1 + n2 + carry);
        ret.insert(ret.begin(), (res % 10) + 0x30);
        carry = res/10;
    }
    if (carry != 0) ret.insert(ret.begin(), carry + 0x30);

    //Remove leading 0s
    for (auto c = ret.begin(); c != ret.end(); c++){
        if (*c != 0x30){
            return std::string(c, ret.end());
        }
    }

    return ret;
}

int main(){
    std::cout << sum_strings("00123", "00900") << std::endl;
}