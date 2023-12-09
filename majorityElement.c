#include <stdio.h>
#include <stdlib.h>

int compareFun(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int majorityElement(int* nums, int numsSize) {
    if (numsSize == 1){return nums[0];}
    qsort(nums, numsSize, sizeof(int), compareFun);
    int counter = 1;
    int i = 1;
    while (counter <= numsSize / 2) {
        if (nums[i] != nums[i-1]) {
            counter = 1;
        } else {
            counter++;
        }
        i++;
    }
    return nums[i-1];
}

int main() {
    int numsSize = 3;
    int nums[3] = {3,3,3};
    int res = majorityElement(nums, numsSize);
    printf("Result: %d", res);
}