#include "./minh_hash/HashOps.h"
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:

    int myAtoi(string s) {
        int res;  
        int i = 0;  
        while (i < s.length()){
            if (!hash_map.get(s[i], value)){
                // NaN
                break;
            }
            res = 
            i++;
        }

        return 1;
    }
private:
    HashOps<int, string, hash_F> hash_map;
    string value;
    

    void initHash(){
        for (int i = 0; i < 10; i++){
        hash_map.put(i, std::to_string(i));
        }
    }

    int parseNums(int prev_num, int add_num){
        return ((prev_num*10) + add_num);
    }
};

int main(){ 
    // string s = "134hello";
    // Solution sol;
    // int res = sol.myAtoi(s);
    // cout << res << endl;
}   
