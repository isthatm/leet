#include <iostream>
#include <vector>
using namespace std;

/*
Notices:
    - handle overflow
    - handle cases where the size of the subarray = 1 DONE
    - handle cases when a solution is not available DONE
    - Use for loop for better clarity
*/

class Solution {
public:
    int minSizeSubarray(vector<int>& nums, int target) {
        int org_size = nums.size();
        nums.insert(nums.end(), nums.begin(), nums.end());
        current_sum = init_sum(nums);
        // current_sum = 1;
        
        // Sliding
        vector<int>::iterator i = nums.begin()+1;
        while (true){
        // for (vector<int>::iterator i = nums.begin(); i != (nums.end() - window_size); i++){
            // if (window_size == 3){
            //     for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
            //         cout << *i << "; " << endl;
            //     }
            //     break;
            // }
            // cout << "Size: "<< window_size << endl;
            // // current_sum = 2;
            // if (window_size == 3){
            //     break;}
            if (window_size == 1){
                current_sum = *i;
            } else{
                current_sum = current_sum - *(i-1) + *(i+window_size-1); 
                cout << current_sum << endl;   
            }      

            if (window_size == 2){
                if (current_sum < target){
                    notFound = false;
                }
                if (
                    i == (nums.end() - org_size) &&
                    notFound
                ){ return -1; }
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
            return -1;
    }  

private:
    int window_size = 1;
    int current_sum = 0;
    bool notFound = true;

    int init_sum (vector<int> &curr_nums){
        int init_window = 0;
        for (vector<int>::iterator i = curr_nums.begin(); i != curr_nums.begin() + window_size; i++){
            // cout << init_window << endl;
            init_window += *i;
        }
        // cout << "init: " << init_window << endl;

        return init_window;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {2, 4, 6, 8};
    int res = sol.minSizeSubarray(nums, 3);
    cout << "Minimum subarray length: " << res << endl;
}