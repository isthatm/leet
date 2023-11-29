#include <iostream>
#include <vector>
using namespace std;

/*
Notices:
    - handle overflow
    - handle cases where the size of the subarray = 1
    - handle cases when a solution is not available
    - can use for loop
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

            if (current_sum == target){
                return window_size;
            } 
            
            current_sum = current_sum - *(i-1) + *(i+window_size-1); 
            cout << current_sum << endl;          
            
            if (i == (nums.end() - org_size)){
                cout << "End window: "<< endl;
                // cout << "Found" << endl;
                // break;
                window_size++;
                if (window_size > (nums.size() - org_size + 1)){
                    nums.insert(nums.end(), nums.begin(), nums.end());
                }
                i = nums.begin()+1;
                current_sum = init_sum(nums);
                continue;
            }
            // switch (window_size){
            //     case 1:
            //         current_sum = *i;
            //         continue;
            //     case 2:
            //         if (current_sum < target){
            //             notFound = false;
            //         }
            //         if (
            //             i == (nums.end() - nums.size() / 2) &&
            //             notFound
            //         ){ return -1; }
            //     default:
            //         break;
            // }
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
        cout << "init: " << init_window << endl;

        return init_window;
    }
};


int main(){
    Solution sol;
    vector<int> nums = {1,2,3,4,5,6,7};
    int res = sol.minSizeSubarray(nums, 10);
    cout << "Minimum subarray length: " << res << endl;
}