#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    if (numsSize <= 2){ return numsSize; }
    int ptr_1 = 1;
    int ptr_2 = 2;
    while (ptr_2 < numsSize) {
        if (
            nums[ptr_2] == nums[ptr_1] && 
            nums[ptr_2] == nums[ptr_1-1]
        ) {
            ptr_2++;
        } else {
            ptr_1++;
            nums[ptr_1] = nums[ptr_2];
            ptr_2++;
        }
    }
   return ptr_1 + 1;   
}

int main() {
    int size = 4;
    int nums[] = {1,1,1,1};
    int res = removeDuplicates(nums, size);
    for (int i = 0; i < res; i++) {printf("\n %d", nums[i]);}
}