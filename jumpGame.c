#include <stdio.h>
#include <stdbool.h>

bool canJump(int* nums, int numsSize) {
    bool res = true;
    int current_furthest = nums[0];
    if (numsSize == 1) {return res;}
    for (int i = 0; i < numsSize; i++) {
        if (current_furthest + 1 >= numsSize){return true;}
        res = (nums[current_furthest] == 0) ? false : true;
        if (i == current_furthest && res == false){break;}
        if (nums[i] + i > current_furthest) {
            current_furthest = nums[i] + i;
        }
    }
    return res;
}

int main() {
    int numsSize = 3;
    int nums[] = {2,0,0}; 
    bool res = canJump(nums, numsSize);
    printf("Can reach last index: %d \n", res);
}