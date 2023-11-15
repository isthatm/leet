#include "HashMap.h"

int main(){
    HashMap<int, string, MyKeyHash> hmap;
    hmap.put(1, "val1");
    // hmap.put(2, "val2");
    // hmap.put(3, "val3");
    hmap.put(11, "val11");
    hmap.put(21, "val21");

    string value;
    hmap.get(11, value); // "value" is changed by referencing
    // cout << value << endl;
    // bool res = hmap.get(3, value);
    // bool res = hmap.get(11, value);
    // if (res)
    //     cout << value << endl;
    //     cout << "heyyy" << ", " << value << endl;
    
    // hmap.remove(3);
    // res = hmap.get(3, value);
    cout << "=========" << endl;
    int a = 5;
    int* b = &a;
    int** c = &b;
    cout << &b << endl;
    // cout << c << endl;
}