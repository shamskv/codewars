#include <iostream>
#include <string>
#include <map>

int solution(std::string roman) {
  
  std::map<char, int> values;

  values['I'] = 1;
  values['V'] = 5;
  values['X'] = 10;
  values['L'] = 50;
  values['C'] = 100;
  values['D'] = 500;
  values['M'] = 1000;

  int curr = 1, sum = 0;
  for (int i = roman.length()-1; i >= 0; i--){
    char num = roman[i];
    if (values[num] >= curr){
      sum += values[num];
      curr = values[num];
    } else {
      sum -= values[num];
    }
  }

  return sum;
}

int main(){

  std::cout << solution("V") << std::endl;
  std::cout << solution("IV") << std::endl;
  std::cout << solution("III") << std::endl;
  std::cout << solution("XCII") << std::endl;
}