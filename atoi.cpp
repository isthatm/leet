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
        bool is_minus = false;
        while (i < s.length()){
            int ASCII_key = (int)char(s[i]);
            if (!hash_map.get(ASCII_key, value)){
                if (!valid_counter){
                    switch (ASCII_key){
                        case 32: // "space"
                            i++;
                            continue;
                        case 43: // "+"
                            i++;
                            continue; 
                        case 45: // "-"
                                is_minus = true;
                                i++;
                                continue; 
                        default:
                            break;
                    } 
                } 
                break; 
            } else {
                valid_counter++;
                bool available = hash_map.get(ASCII_key, value);
                res = parseNums(res, value);
                if (res == INT32_MAX){
                    break;
                }
            }
        i++;
        }

        if (is_minus) {return -res;}
        return res;
    }

private:
    HashOps<int, int, int_hash> hash_map;
    int value;

    int parseNums(int prev_num, int num){ 
        try{
            if (prev_num != 0 && INT32_MAX / prev_num < 10){
                throw range_error("INT32 overflow will occur");
            }
        }
        catch (range_error err){
            return INT32_MAX;
        }
        int res = (prev_num*10) + num; 
        return res;
    }
};

int main(){ 
    string s = "-91283472332";
    Solution sol;
    int res = sol.myAtoi(s);
    cout << res << endl;
    // const char* str = "-91283472332";
    // cout << atoi(str) << endl;
    // char a = '5';
    // char* ptr = &a;
    // cout << hash_function(ptr) << endl;
}   

// int main()
// {
//    int x = -1;
 
//    // Some code
//    cout << "Before try \n";
//    try {
//       cout << "Inside try \n";
//       if (x < 0)
//       {
//          throw x;
//          cout << "After throw (Never executed) \n";
//       }
//    }
//    catch (int x ) {
//       cout << "Exception Caught: " << x << endl;
//    }
 
//    cout << "After catch (Will be executed) \n";
//    return 0;
// }