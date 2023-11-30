#include <iostream>
#include <vector>
#define __STDC_LIMIT_MACROS
#include <stdint.h>

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
        // for (vector<int>::iterator = nums.begin(); i != nums.end(); i++){cout << i << " ;"}
        // Sliding
        vector<int>::iterator i = nums.begin()+1;
        
        // cout << "Start: " << org_nums.size() << endl;
        while (true){
            for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){cout << *i << " ;";}
            // if (window_size == 30){break;}
            try {
                int idx = i - nums.begin();
                if (current_sum == target){
                    return window_size;
                } 
               
                if (window_size == 1){
                    current_sum = *i;
                } else{
                    current_sum = current_sum - *(i-1);
                    overflowCheck(current_sum, *(i-1+window_size));
                    current_sum += *(i-1+window_size); 
                    // cout << current_sum << endl;   
                }  
                cout << "current window: " << window_size << "; Current i: " << idx << "; Current Sum: "<< current_sum << "; Add: " << *(i-1+window_size)  << endl;  

                if (current_sum == target){
                    return window_size;
                }               
                if (current_sum < target){
                    notFound = false;
                }
                               
                // try new window size
                if (i == (nums.begin() + org_nums.size() - 1)){ 
                    cout << "Window stops at: " << *i << endl;
                    if (notFound) { cout <<"Not found."<< endl; break; }
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
                // cout << msg.what() << ": " << current_sum << endl;
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
            cout << "    Overflow: " << a << "; " << b << endl;
            throw overflow_error("Integer overflow.");
        }
    }
};


int main(){
    Solution sol;
    // vector<int> nums = {1,2,3};
    vector<int> nums = {8}; // target = 85
    // vector<int> nums = {2,1,5,7,7,1,6,3}; // target = 39
    int res = sol.minSizeSubarray(nums, 68);
    cout << "Minimum subarray length: " << res << endl;
    // // cout << 8 % 3 << endl;
}