#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef vector<int> vct;

class Solution {
public:
    int removeElement(vct& nums, int val) {
        nums.erase(remove(nums.begin(), nums.end(), val), nums.end());
        return nums.size();
    }
};

int main() {
    Solution sol;
    vct nums = {3,2,2,3};
    int val = 3;
    int res = sol.removeElement(nums, val);
    cout << "Remaining size: " << res << endl;
}