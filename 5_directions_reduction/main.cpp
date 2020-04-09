#include<algorithm>
#include<vector>
#include<string>
#include<iostream>

#define NS 78+83
#define EW 69+87

void print_arr(std::vector<std::string> &arr);

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr);
};

std::vector<std::string> DirReduction::dirReduc(std::vector<std::string> &arr){

    bool did_change = true;

    while(did_change){
        did_change = false;

        if(arr.size() < 2){
            return arr;
        }

        for(auto it = arr.begin(); it+1 != arr.end() && it != arr.end(); it++){
            std::string& word1 = *it;
            std::string& word2 = *(it+1);

            if(word1.size() == word2.size() && word1[0] != word2[0]){
                *(it)="R";
                *(it+1)="R";
                it++;
                did_change = true;
            }
        }
        if(did_change){
            arr.erase(std::remove(arr.begin(), arr.end(), "R"), arr.end());
        }
    }

    return arr;
}

void print_arr(std::vector<std::string> &arr){
    for(auto& ref : arr){
        std::cout << ref << " ";
    }
    std::cout << std::endl;
}

int main(){

    std::vector<std::string> d1 = {"EAST", "SOUTH", "NORTH", "WEST", "NORTH", "WEST", "WEST", "WEST", "EAST", "WEST", "WEST", "EAST", "SOUTH", "WEST", "NORTH", "WEST", "WEST", "NORTH", "SOUTH", "NORTH"};
    std::vector<std::string> d2 = {"NORTH", "SOUTH", "SOUTH", "EAST", "WEST", "NORTH", "WEST"};

    print_arr(d1);
    DirReduction::dirReduc(d1);
    print_arr(d1);
}
