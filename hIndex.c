#include <stdio.h>

/*
    Testcase:
    [3,0,6,1,5]
    [1,3,1]
    [4,4,4,4,4,4,5]
    [3, 1, 7, 8, 9]
*/

int hIndex(int* citations, int citationsSize) {
    
}

int main() {
    int citationsSize = 5;
    int citations[] = {3,0,6,1,5};
    int res = hIndex(citations, citationsSize);
    printf("H-index = %d \n", res);
}