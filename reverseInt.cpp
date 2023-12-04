#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        int temp = x;
        while (temp != 0) {
            temp /= 10;
            x = (temp % 10) + temp*10;
        }
        
    }
};

int main() {
    Solution sol;
    int x = 123;
    int res = sol.reverse(x);
    cout << "Inversed x = " << res << endl;
}