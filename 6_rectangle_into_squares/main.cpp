#include <vector>

class SqInRect
{
  public:
  static std::vector<int> sqInRect(int lng, int wdth);
};

std::vector<int> SqInRect::sqInRect(int lng, int wdth){
    std::vector<int> squares;

    if(lng == wdth) return squares;

    while (lng > 0 && wdth > 0){
        //length is always the biggest dimension
        if (lng < wdth) std::swap (lng, wdth);
        lng -= wdth;
        squares.push_back(wdth);
    }

    return squares;
}