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
    [5]
    [0]
    [2,3,3,3]
*/

int compare (const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}

int hIndex(int* citations, int citationsSize) {
    if (citationsSize == 1) {return citations;}
    qsort(citations, citationsSize, sizeof(int), compare);
    int i = 0;
    int h_idx = citations[0];
    while (i < citationsSize) {
        if (citations[i] != h_idx) {
            if (citationsSize - i >= h_idx) {
                h_idx = i;
            }
        }
        i++;
    }
    
}

int main() {
    int citationsSize = 5;
    int citations[] = {3,0,6,1,5};
    int res = hIndex(citations, citationsSize);
    printf("H-index = %d \n", res);
}