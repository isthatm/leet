#include <iostream>
#include <vector>
#define __STDC_LIMIT_MACROS
#include <stdint.h>
#include <chrono>

using namespace std;

/*
Notices:
    - handle overflow
    - handle cases where the size of the subarray = 1 DONE
    - handle cases when a solution is not available DONE
    - if all windows in within a window size > target -> not viable also
*/

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        if (nums.size() == 1){
            if (nums[0] > target){ return -1;}
            else if(target % nums[0] == 0){ return target / nums[0];}
            else {return -1;}
        }
        
        vector<int> org_nums = nums;
        append_at = org_nums.size() + 2;
        nums.insert(nums.end(), org_nums.begin(), org_nums.end());
        current_sum = init_sum(nums);
     
        // Sliding
        vector<int>::iterator i = nums.begin()+1;
        
        while (true){
            try {
                // int idx = i - nums.begin();
                if (current_sum == target){
                    return window_size;
                } 
               
                if (window_size == 1){
                    current_sum = *i;
                } else{
                    current_sum = current_sum - *(i-1);
                    overflowCheck(current_sum, *(i-1+window_size));
                    current_sum += *(i-1+window_size); 
                }  
                // cout << "current window: " << window_size << "; Current i: " << idx << "; Current Sum: "<< current_sum << "; Add: " << *(i-1+window_size)  << endl;  

                if (current_sum == target){
                    return window_size;
                }               
                if (current_sum < target){
                    notFound = false;
                }
                               
                // try new window size
                if (i == (nums.begin() + org_nums.size() - 1)){ 
                    // cout << "Window stops at: " << *i << endl;
                    if (notFound) { 
                        break; 
                    }
                    else { notFound = true; }
                    window_size++;
                    if (window_size == append_at){
                        append_at += org_nums.size();
                        nums.insert(nums.end(), org_nums.begin(), org_nums.end());
                    }
                    i = nums.begin() + 1;
                    current_sum = init_sum(nums);
                    continue;
                }
                i++;
            }   
            catch (overflow_error msg){
                return -1;
            }
        }
            cout << "Out" << endl;
            return -1;
    }  

private:
    int window_size = 1;
    int current_sum = 0;
    bool notFound = true;
    int append_at;

    int init_sum (vector<int> &curr_nums){
        int init_window = 0;
        for (vector<int>::iterator i = curr_nums.begin(); i != curr_nums.begin() + window_size; i++){
            init_window += *i;
        }

        return init_window;
    }

    void overflowCheck(int a, int b){
        if (INT32_MAX - b < a){
            // cout << "    Overflow: " << a << "; " << b << endl;
            throw overflow_error("Integer overflow.");
        }
    }
};


int main(){

    Solution sol;
    // vector<int> nums = {8,10,1,13,1,2,1,13,13,11,7,8,10,8,4,8,5,5,10,2}; // target = 85
    vector<int> nums = {60084,23369,61831,23772,7826,5873,48429,8705,52687,62301,13700,41302,54544,57165,12325,15252,10287,33520,43163,6206,37310,25511,29615,7672,40678,19425,8391,17751,45673,19834,38436,37296,52596,54554,2234,5434,3673,25437,21913,16441,43378,6954,60176,32693,46022,57368,54741,6787,61010,32945,35353,5804,1460,47306,22955,37105,28131,4873,3632,20279,21170,51870,38972,36229,28587,39984,53190,28604,45130,27205,1536,27644,361,45049,51646,11255,28112,27093,12286,36844,47701,872,45909,54320,62687,19158,16140,21886,17431,55125,31310,43907,811,26534,2756,26681,7488,44290,27573,13809,63448,59776,48705,9664,1300};
    auto start = chrono::high_resolution_clock::now();
    int res = sol.minSizeSubarray(nums, 12893248);
    auto stop = chrono::high_resolution_clock::now();

    cout << "Minimum subarray length: " << res << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start); 
    cout << "Execution time: " << duration.count() << "us" <<endl;
}