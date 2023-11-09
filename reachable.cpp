#include <iostream>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int chebyshev_dis = max(abs(sx - fx), abs(sy - fy));
        if (
            (sx == fx) && (sy == fy)
        ){
            if (
                (t >= 2) || (!t)
            ){
                return true;
            } else{
                return false;
            }
        } else if (t >= chebyshev_dis){
            return true;
        } else{
            return false;
        }
    }
};

int main(){
    Solution sol;
    bool res = sol.isReachableAtTime(1, 1, 1, 1, 3);
    cout << res << endl;
}