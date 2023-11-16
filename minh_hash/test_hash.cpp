#include "HashOps.h"
#include <iostream>
using namespace std;

int main(){
    HashOps<int, string, hash_F> hash_map;
    string value;
    bool res;
    hash_map.put(1, "one");
    hash_map.put(2, "two");
    hash_map.put(11, "eleven");
    hash_map.put(21, "twenty one");
    hash_map.put(12, "twelve");
    hash_map.put(22, "twenty two");
    hash_map.put(32, "thirty two");
    res = hash_map.get(22, value);
    cout << res << ", " << value << endl;
    res = hash_map.get(2, value);
    cout << res << ", " << value << endl;

    // int a = 5;
    // int* s_ptr = &a;
    // int** d_ptr = &s_ptr;
    // cout << s_ptr << endl;
    // cout << *d_ptr << endl;  
}