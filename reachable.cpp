#include <iostream>
using namespace std;

class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        int chebyshev_dis = max(abs(sx - sy), abs(fx - fy));
        if (
            (sx == fx) && (sy == fy)
        ){
            return false;
        } else {
            t >= chebyshev_dis;
            return true;
        }
    }
};

