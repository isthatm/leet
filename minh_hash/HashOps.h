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
    NOTES:
    - Should not use double pointer MinhNode<K, V>** current_node as updating 
      through *current_node = (*current_node)->getNext();
      actually updates the starting node of the bucket since the *ptr in dynamic array
      always points to the first element
*/

class int_hash{
public:
    int operator()(const int &key) const{ // reference to a constant
    // Changing the value of this reference is invalid
        return key % 10;
    }
};

class char_hash{
public:
    unsigned long operator()(const char* str){
        unsigned long i = 0;

        for (int j = 0; str[j]; j++){
            i += str[j];
        }

        return i % TABLE_SIZE;
    }
};

template <typename K, typename V, typename F>
class HashOps{
public:
    HashOps(){
        hash_table = new MinhNode<K,V>* [TABLE_SIZE](); // A dynamic array of pointers to NULL
        // designated to point to another array
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
        auto hash_value = hash_func(key);
        MinhNode<K,V>* current_node = hash_table[hash_value];

        if (!hash_table[hash_value]){// No key in this bucket
            hash_table[hash_value] = new MinhNode<K, V> (key, value);
        } else{// put it at the end of the list in this bucket
            while (true){
                if (current_node->getKey() == key){
                    current_node->updateValue(value);
                    break;
                }
                if (!(current_node->getNext())){
                    current_node->setNew(key, value);
                    break;
                }
                current_node = current_node->getNext();
            }
        }
    }

    bool get(K key, V &value){
        auto hash_value = hash_func(key);
        MinhNode<K,V>* current_node = hash_table[hash_value];
        if (!current_node){
            // value = "Not found";
            return false;
        } else{
            while(current_node != NULL){
                if (key == current_node->getKey()){
                    value = current_node->getValue();
                    return true;
                }
                current_node = current_node->getNext();
            }
            // value = "Not found";
            return false;
        }
    }

    void remove(K key){
        auto hash_value = hash_func(key);
        MinhNode<K,V>* current_node = hash_table[hash_value];
        MinhNode<K,V>* prev_node = NULL;

        if (!current_node){
            cout << "Value is not available for removal" << endl;
            return;
        } else{
            while(current_node != NULL){
                if (key == current_node->getKey()){
                    if (!prev_node){
                        hash_table[hash_value] = current_node->getNext();
                        return;
                    }

                    prev_node->setNext(current_node->getNext());
                    delete current_node;
                    delete prev_node;
                    return;
                }
                prev_node = current_node;
                current_node = current_node->getNext();
            }  
        }
        cout << "Value is not available for removal" << endl;
        delete prev_node;
    }

private:
    MinhNode<K, V>** hash_table; 
    F hash_func;
};