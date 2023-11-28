#include <iostream>
using namespace std;
int repeatedNumber(int arr[], size_t arr_length){
    int start_idx = 0;
    int end_idx = arr_length;
    int mid_idx = (end_idx - start_idx) / 2;

    // Repeated number is on the right
    while (arr[mid_idx] > mid_idx){
        start_idx = mid_idx;
        mid_idx = ((end_idx - start_idx) / 2) + start_idx;

    }

    // Repeated number is on the left
    while (arr[mid_idx-1] != arr[mid_idx])
    {
        end_idx = mid_idx;
        mid_idx = end_idx  / 2;
        if (mid_idx == 2){
            break;
        }
    }
    
    return arr[mid_idx];
}

int main(){
    int arr[] = {1, 2, 3, 4, 5, 6, 6, 7, 8, 9, 10, 11};
    int res = repeatedNumber(arr, sizeof(arr) / sizeof(int));
    cout << res << endl;
}