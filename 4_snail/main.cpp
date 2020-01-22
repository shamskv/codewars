#include <vector>
#include <iostream>

std::vector<int> snail(std::vector<std::vector<int> > snail_map) {

  int n = snail_map.size();

  if(n == 1){
      return snail_map[0];
  }

  std::vector<int> result;
  
  for (int s = 0; s < (n-1)/2 + 1; s++){
    int i=s;
    int j=s;

    if(n % 2 == 1 && n/2 == s){
        result.push_back(snail_map[s][s]);
        break;
    }

    for (j = s; j < n - s; j++){
        std::cout << "line 1 "<< s << j << std::endl;
        result.push_back(snail_map[s][j]);
    }

    for(i = s+1; i < n - s; i++){
        std::cout << "line 2 "<< i << n-s-1 << std::endl;
        result.push_back(snail_map[i][n-s-1]);
    }

    for(j= n-s-2 ; j >= s; j--){
        std::cout << "line 3 "<< n-s-1 << j << std::endl;
        result.push_back(snail_map[n-s-1][j]);
    }

    for(i= n-s-2 ; i > s; i--){
        std::cout << "line 4 "<< i << s << std::endl;
        result.push_back(snail_map[i][s]);
    }

    std::cout << "end " << s << std::endl;
  }
  
  return result;
}

int main(){

    std::vector<std::vector<int> > input{{}};

    std::vector<int> res = snail(input);

    // for (int i : res){
    //     std::cout << i << std::endl;
    // }

    return 0;
}