#include <stdio.h>

int removeDuplicates(int* nums, int numsSize) {
    int* ptr = nums;
    int* del_ptr = nums + 2;
    int com = *del_ptr == 0;
    printf("%d \n", com);

    return -1;
}


int main() {
    // int nums[17] = {-1,-1,1,1,2,2,3,3,3,4,5,5,6,7,7,7,7};
    int nums[2] = {1, 2};
    int res = removeDuplicates(nums, 1);
    printf("%d", res);
}