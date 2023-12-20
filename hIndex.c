#include <stdio.h>
#include <stdlib.h>

/*
    Testcase:
    [3,0,6,1,5]
    [1,3,1]
    [4,4,4,4,4,4,5]
    [3, 1, 7, 8, 9]
    [3,4]
    [0,1]
    [1,2]
    [5]
    [0]
    [2,3,3,3]
    [4,4,0,0] - Expect hIndex = 2
    [1,3,3] - Expect hIndex = 2
*/

int compare (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int hIndex(int* citations, int citationsSize) {
    qsort(citations, citationsSize, sizeof(int), compare);
    int i = 0;
    int h_idx = citationsSize;
    int remainings;
    while (i < citationsSize) {
        remainings = citationsSize - i;
        if (citations[i] <= remainings) {
            h_idx = citations[i];
        } else {
            h_idx = (remainings > h_idx) ? remainings : h_idx;
        }
        i++;
    }   
    return h_idx;    
}

int main() {
    int citationsSize = 5;
    int citations[] = {3,0,6,1,5};
    int res = hIndex(citations, citationsSize);
    printf("H-index = %d \n", res);
}