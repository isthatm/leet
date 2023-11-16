#include <iostream>
#include "MinhNode.h"
#include "HashFun.h"
using namespace std;

/*
    There is a trade off between table size and map collision
    E.g. Provided that keys are integers and key ranges from 1 -> 100:
        + Keys of values 1, 11, 21, etc. would collide in a table size of 10 
        + This would not occur of a table size of 100 as each key will be stored
          in a separate bucket
*/

class hash_F{
public:
    int operator()(const int &key) const{ // reference to a constant
    // Changing the value of this reference is invalid
        return key % 10;
    }
};

template <typename K, typename V, typename F = HashFun<K>>
class HashOps{
public:
    HashOps(){
        hash_table = new MinhNode<K,V>* [TABLE_SIZE](); // A dynamic array of pointers to NULL
    }

    ~HashOps(){
        MinhNode<K,V>* current_node = NULL;
        MinhNode<K,V>* prev_node = NULL;
        // delete all lists of nodes within a bucket
        // then delete the buckets
        for (int i = 0; i < TABLE_SIZE; i++){
            current_node = hash_table[i];
            while(current_node != NULL){
                prev_node = current_node;
                current_node = current_node->getNext();
                delete prev_node;
            }
        }
        delete[] hash_table;
    }

    void put(K key, V value){
        // allocate the values to buckets on the heap
        int hash_value = hash_func(key);
        MinhNode<K,V>* current_node = hash_table[hash_value];
        if (!hash_table[hash_value]){// No key in this bucket
            hash_table[hash_value] = new MinhNode<K, V> (key, value);
        } else{// put it at the end of the list in this bucket
            while (true){
                if (!(current_node->getNext())){
                    break;
                }
                current_node = current_node->getNext();
            }
            current_node->setNext(key, value);
        }
    }

    bool get(K key, V &value){
        int hash_value = hash_func(key);
        MinhNode<K,V>* current_node = hash_table[hash_value];
        if (!current_node){
            return false;
        } else{
            while(current_node != NULL){
                if (key == current_node->getKey()){
                    value = current_node->getValue();
                    return true;
                }
                current_node = current_node->getNext();
            }
            return false;
        }
    }

    void remove(){
    }

private:
    MinhNode<K, V>** hash_table; 
    F hash_func;
};