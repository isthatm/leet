#include "./minh_hash/HashOps.h"
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    Solution(){
        for (int i = 0; i < 10; i++){
            hash_map.put(48 + i, i); // inserting ASCII
        }
    }

    int myAtoi(string s) {
        int res = 0; //default is 0 
        int i = 0;  
        while (i < s.length()){
            if (!hash_map.get((int)char(s[i]), value)){
                // NaN
                break;
            }
            res = parseNums(7);
            i++;
        }
        return 1;
    }

private:
    HashOps<int, int, int_hash> hash_map;
    int value;

    int parseNums(int num){
        static int add_num = 0; 
        return ((num*10) + add_num);
    }
};

int main(){ 
    string s = "134hello";
    Solution sol;
    int res = sol.myAtoi(s);
    // cout << res << endl;
    // const char* str = "123lol";
    // cout << atoi(str) << endl;
    // char a = '5';
    // char* ptr = &a;
    // cout << hash_function(ptr) << endl;
}   
