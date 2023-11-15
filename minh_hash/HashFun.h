int TABLE_SIZE = 10; // this is equal to the number of buckets
// one bucket can contain many keys EX: bucket 1 can contain key 1 and 11 
template <typename K>
class HashFun{
    int operator()(const K &key) const{ // reference to a constant
    // Changing the value of this reference is invalid
        return key % TABLE_SIZE;
        
    }
};