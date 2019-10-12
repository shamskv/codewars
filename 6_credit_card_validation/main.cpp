#include <iostream>
#include <vector>
#include <algorithm>

class Kata {
  public:
  static bool validate(long long int n) {
    std::vector<int> digits;
    //Separate into digits
    while (n > 0){
        digits.insert(digits.begin(), n % 10);
        n /= 10;
    }
    //Do the maths
    for (int i = digits.size() % 2; i < digits.size(); i+=2){
        digits[i] *= 2;
        if (digits[i] > 9){
            digits[i] -= 9;
        }
    }

    //Sum
    int sum = 0;
    std::for_each(digits.begin(), digits.end(), [&] (int n) {sum += n;});
    return sum % 10 == 0;
  }
};

int main(){
    std::cout << Kata::validate(891);
    std::cout << Kata::validate(2121);
}