#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        vector<int>::iterator p_ptr = nums.begin();
        vector<int>::iterator i = nums.begin()+1;
        while(true){
            if (
                i == nums.end() || (*i - *(i-1)) != 0
            ) {
                nums.erase(p_ptr, i-1);
                i -= (i - p_ptr) - 1; 
                p_ptr ++;
            }
            if (i == nums.end()) {break;}
            i++;
        }      
        return nums.size();
    }
};

int main() {
    Solution sol;
    vector<int> nums = {-1,-1,1,1,2,2,3,3,3,4,5,5,6,7,7,7,7};
    int res = sol.removeDuplicates(nums);
    for (vector<int>::iterator i = nums.begin(); i != nums.end(); i++){cout << *i << " " << endl;}
}