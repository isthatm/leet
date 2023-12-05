#include <iostream>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = x;
        long res = temp;
        res = 0;
        while (temp != 0) {
            res = (res +  temp % 10);
            temp /= 10;
            if (temp != 0) {res *= 10;}
        }
        if (INT16_MIN >= res) {
            return 0;
        } else if (res >= INT16_MAX) {
            return 0;
        }
        return res;
    }
};

int main() {
    Solution sol;
    int x = -123;
    int res = sol.reverse(x);
    cout << "Inversed x = " << res << endl;
}