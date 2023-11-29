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
        int org_size = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        current_sum = init_sum(nums);
        // for (vector<int>::iterator = nums.begin(); i != nums.end(); i++){cout << i << " ;"}
        // Sliding
        vector<int>::iterator i = nums.begin()+1;
        while (true){
            cout << "current window: " << window_size << endl;
            for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){cout << *i << " ;";}
            try {
                if (window_size == 1){
                    current_sum = *i;
                } else{
                    current_sum = current_sum - *(i-1);
                    overflowCheck(current_sum, *(i+window_size-1));
                    current_sum += *(i+window_size-1); 
                    cout << current_sum << endl;   
                }      

                if (window_size == 2){
                    if (current_sum < target){
                        notFound = false;
                    }
                    if (
                        i == (nums.end() - org_size) &&
                        notFound
                    ){ cout << "Not viable" << endl;return -1; }
                }

                if (current_sum == target){
                    return window_size;
                }  
                
                if (i == (nums.end() - org_size)){
                    window_size++;
                    if (window_size > (nums.size() - org_size + 1)){
                        nums.insert(nums.end(), nums.begin(), nums.end());
                    }
                    i = nums.begin() + 1;
                    current_sum = init_sum(nums);
                    continue;
                }
                i++;
            }   
            catch (overflow_error msg){
                cout << msg.what() << ": " << current_sum << endl;
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

    int init_sum (vector<int> &curr_nums){
        int init_window = 0;
        for (vector<int>::iterator i = curr_nums.begin(); i != curr_nums.begin() + window_size; i++){
            init_window += *i;
        }

        return init_window;
    }

    void overflowCheck(int a, int b){
        if (INT32_MAX - b < a){
            cout << a << ", " << b << endl;
            throw overflow_error("Integer overflow.");
        }
    }
};


int main(){
    Solution sol;
    vector<int> nums = {17,4,3,14,17,6,15};
    int res = sol.minSizeSubarray(nums, 30);
    cout << "Minimum subarray length: " << res << endl;
}