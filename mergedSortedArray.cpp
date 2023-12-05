#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
using namespace std;


class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int start = 0;
        vector<int> nums3(m+n);
        std::merge(nums1.begin(), nums1.begin()+m, nums2.begin(), nums2.begin()+n, nums3.begin());
        
        for (int i = m; i < m+n; i++) {
            int j = i;
            while (j > start) {
                if (nums1[j] <= nums1[j-1]) {
                    temp = nums1[j];
                    nums1[j] = nums1[j-1];
                    nums1[j-1] = temp;
                }
                j--;
            }
            start = j;
        }
        for(int i = 0; i < nums3.size(); i++){nums1[i] = nums3[i];}
    }

private:
    int temp;
};


int main() {
    Solution sol;
    vector<int> nums1 = {-1,0,0,3,3,3,0,0,0};
    vector<int> nums2 = {1,2,2,0,0};

    sol.merge(nums1, 6, nums2, 3);
    for(vector<int>::iterator i = nums1.begin(); i != nums1.end(); i++){cout << *i << " ";}
}
