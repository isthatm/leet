#include <iostream>
#include <algorithm>
#include <vector>
#define __STDC_LIMIT_MACROS
#include <chrono>
#define UPPER_BOUND 1e5 + 1
using namespace std; 

typedef vector<int> vct;
/*
Notices:
    - handle overflow
    - handle cases where the size of the subarray = 1 DONE
    - handle cases when a solution is not available DONE
    - if all windows in within a window size > target -> not viable also
*/

class Solution1 {
public:
    int minSizeSubarray(vct& nums, int target) {
        if (nums.size() == 1){
            if (nums[0] > target){ return -1;}
            else if(target % nums[0] == 0){ return target / nums[0];}
            else {return -1;}
        }
        
        vct org_nums = nums;
        append_at = org_nums.size() + 2;
        nums.insert(nums.end(), org_nums.begin(), org_nums.end());
        current_sum = init_sum(nums);
     
        // Sliding
        vct::iterator i = nums.begin()+1;
        
        while (true){
            try {
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

                if (current_sum == target){
                    return window_size;
                }               
                if (current_sum < target){
                    notFound = false;
                }
                               
                // try new window size
                if (i == (nums.begin() + org_nums.size() - 1)){ 
                    if (notFound) { break; }
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

    int init_sum (vct &curr_nums){
        int init_window = 0;
        for (vct::iterator i = curr_nums.begin(); i != curr_nums.begin() + window_size; i++){
            init_window += *i;
        }

        return init_window;
    }

    void overflowCheck(int a, int b){
        if (INT32_MAX - b < a){
            throw overflow_error("Integer overflow.");
        }
    }
};

class Solution2{
public:
    /*
        Approach:
            1. Determine if n x sum(nums) = target
            2. Find the remainder -> the remainder is the new target
            3. Construct a temporary nums vector from 2 nums vectors to implement 2.
    */
    int minSizeSubarray(vector<int> &nums, int target){
        vector<int> temp = nums;
        temp.insert(temp.end(), nums.begin(), nums.end());
        for(int i = 0; i<nums.size(); i++){sums += nums[i];}
        int remainder = target % sums;
        int n_nums = target / sums;
        if (!remainder){return n_nums*nums.size();}
        target = remainder; 
       
        sums = 0;
        int l_ptr = 0;
        for (int r_ptr = 0; r_ptr < temp.size(); r_ptr++){
            sums += temp[r_ptr];
            while (sums > target){
                sums -= temp[l_ptr];
                l_ptr++;
            }
            if (sums == target){
                ans = min(ans, r_ptr - l_ptr + 1);
            }
        }
        if (ans == UPPER_BOUND){return -1;}
        else{return n_nums*nums.size() + ans;}
    }
private:
    long sums = 0;
    int ans = UPPER_BOUND;
};


int main(){
    Solution1 sol;
    vct nums = {1,6,5,5,1,1,2,5,3,1,5,3,2,4,6,6}; // target = 85
    auto start = chrono::high_resolution_clock::now();
    int res = sol.minSizeSubarray(nums, 56);
    auto stop = chrono::high_resolution_clock::now();

    cout << "Minimum subarray length: " << res << endl;

    auto duration = chrono::duration_cast<chrono::microseconds>(stop-start); 
    cout << "Execution time: " << duration.count() << "us" <<endl;
}

