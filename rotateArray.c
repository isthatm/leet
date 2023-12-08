#include <stdio.h>
#include <string.h>

void partialRotation(int* nums, int start, int end) {
    int num_swaps = (end - start + 1) / 2;
    // printf("%d \n", (end - start + 1) / 2);
    while (num_swaps > 0) {
        // printf("HEY %d \n", num_swaps);
        int temp = nums[start];
        nums[start] = nums[end];
        nums[end] = temp;
        start++;
        end--;
        num_swaps--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k = k % numsSize;
    partialRotation(nums, 0, numsSize-1);
    partialRotation(nums, 0, k-1);
    partialRotation(nums, k, numsSize-1);
}

int main() {
    int nums[] = {1,2,3,4,5,6,7};
    int numsSize = 7;
    int k = 3;
    rotate(nums, numsSize, k);
    for (int i = 0; i < numsSize; i++) {
        printf("%d \n", nums[i]);
    }
}
