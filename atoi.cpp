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
        int valid_counter = 0;
        while (i < s.length()){
            int ASCII_key = (int)char(s[i]);
            if ((ASCII_key == 32) &&
                !valid_counter
            ){
                i++;
                continue;
            } else if (!hash_map.get(ASCII_key, value)){
                // NaN
                break;
            } else if (hash_map.get(ASCII_key, value)) {
                valid_counter++;
                bool available = hash_map.get(ASCII_key, value);
                res = parseNums(res, value);
            }
            i++;
        }
        return res;
    }

private:
    HashOps<int, int, int_hash> hash_map;
    int value;

    int parseNums(int prev_num, int num){ 
        return ((prev_num*10) + num);
    }
};

int main(){ 
    string s = " 1 23lol";
    Solution sol;
    int res = sol.myAtoi(s);
    cout << res << endl;
    // const char* str = " -1-23lol";
    // cout << atoi(str) << endl;
    // char a = '5';
    // char* ptr = &a;
    // cout << hash_function(ptr) << endl;
}   
