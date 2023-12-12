class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        num_hash = {}
        for num_idx, num in enumerate(nums):
            complement_num = target - num
            if (complement_num) in num_hash.keys():
                idx_1_loc, idx_2_loc = num_idx, num_hash[complement_num]
            else:
                num_hash[num] = num_idx 
        return idx_1_loc, idx_2_loc