#include <vector>
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

class RemovedNumbers
{
public:
	static vector<vector<long long>> removNb(long long n){
        vector<vector<long long>> result;
        long long sum = n*(n+1)/2;

        for (long long a = 1; a <= (long long) sqrt(sum); a++){
            if ((sum-a) % (a+1) == 0 && (sum-a)/(a+1) <= n){
                cout << a << " " << (sum-a)/(a+1) << endl;
                result.emplace_back(std::initializer_list<long long>{a,(sum-a)/(a+1)});
                result.emplace_back(std::initializer_list<long long>{(sum-a)/(a+1),a});
            }
        }

        sort(result.begin(), result.end(), [] (const vector<long long> &a, const vector<long long> &b){
            return a[0] < b[0];
        });

        return result;
    }
};

int main(){
    RemovedNumbers::removNb(26);
}
