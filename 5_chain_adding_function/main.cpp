#include <iostream>


class MagicInt {
    public:
    int num;

    MagicInt(int n):num(n) {};

    MagicInt operator()(const int value){
        return MagicInt(num+value);
    }

    MagicInt operator+(const int value){
        return MagicInt(num+value);
    }

    MagicInt operator-(const int value){
        return MagicInt(num-value);
    }
};

bool operator==(const MagicInt& m, const int v){
    return m.num == v;
}

bool operator==(const int v, const MagicInt& m){
    return m.num == v;
}

auto add(int n){
    return MagicInt(n);
}

int main(){
    auto my_add = add(5);

    if(my_add + 3 == 8){
        std::cout << "Success\n";
    } else {
        std::cout << "Fail\n";
    }

    return 0;
}