#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
       if (x<0){
        return false;
       } else{
        int reversed_x = reverseInt(x);
        return (x == reversed_x);
       }
    }
private:
    int reverseInt(int x){
        int remainder = x % 10;    
        int rev_x = remainder;
        x /= 10;
        while (x != 0){
            remainder = x % 10;    
            rev_x = (rev_x *10) + remainder ;          
            x /= 10;
        }
        return rev_x;
    }
};

int main(){
    int y = 121;
    Solution sol;
    bool res = sol.isPalindrome(y);
    cout << res << endl;
}