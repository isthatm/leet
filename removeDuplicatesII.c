#include <stdio.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    int res = 0;
    int* ptr_1 = nums;
    int ptr_2 = 1;
    int* end = nums+numsSize-1;
    while (1) {
        if ( 
            *ptr_1 == *(ptr_1+ptr_2)
        ) {
            printf("Are equal. \n");
            ptr_2++;
            continue;
        } else if (
            (ptr_1+ptr_2 == end || *ptr_1 != *(ptr_1+ptr_2) )
        ) {
            printf("got ONCE: %d vs %d", *ptr_1, *(ptr_1+ptr_2));
            printf("\n");
            if (ptr_2 > 1) {
                //Shift
                printf("Shifting \n");
                for (int* i = ptr_1; i < end; i++) {
                    *(i+2) = *(i+ptr_2);
                }
                end -= ptr_2 - 2;
                // printf("END after shifting: %d \n", *end);
                // break;
                ptr_1 += 2;
                ptr_2 = 1;
                continue;
            }
            ptr_2 = 1;
        } 
        if (ptr_1+ptr_2 >= end) {
            break;
        }
        ptr_1++;
    }
    for (int i = 0; i < numsSize; i++){
        if (nums+i == end) {
            res = i+1;
            break;
        }
    }
    return res;
}


int main() {
    // int nums[17] = {-1,-1,1,1,2,2,3,3,3,4,5,5,6,7,7,7,7};
    int size = 1;
    int nums[] = {0};
    int res = removeDuplicates(nums, size);
    // int bool = nums[3] > nums[3];
    // printf("\n %d", res);
    for (int i = 0; i < res; i++) {printf("\n %d", nums[i]);}
    // int a[] = {1,2,3,4,5};
    // int a2[2];
    // memcpy(a2, &a[3], 2*sizeof(*a));
    // for (int i = 0; i < 2; i++) {
    //     printf("%d", a2[i]);
    // }
}