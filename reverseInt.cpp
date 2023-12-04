#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = x;
        x = 0;
        while (temp != 0) {
            x = (x + temp % 10)*10;
            temp /= 10;
        }
        return x / 10;
    }
};

int main() {
    Solution sol;
    int x = -123;
    int res = sol.reverse(x);
    cout << "Inversed x = " << res << endl;
    // cout << 123 / 10 << endl;
}