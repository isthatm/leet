const int TABLE_SIZE = 10; // this is equal to the number of buckets

class int_hash{
public:
    int operator()(const int &key) const{ // reference to a constant
    // Changing the value of this reference is invalid
        return key % 10;
    }
};