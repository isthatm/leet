#include <iostream>
#include "MinhNode.h"
#include "HashFun.h"
using namespace std;

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
        int hash_value = hash_func(key);
        MinhNode<K,V>* current_node = hash_table[hash_value];
        cout << hash_value << endl;
        if (!current_node){// there is no key in this bucket
            current_node = new MinhNode<K, V> (key, value);
            cout << "KEY" << endl;
        } else{// put it at the end of the list of nodes in this bucket
            while (!current_node){// traverese to the end
                cout << "KEY(s)" << endl;
                current_node = current_node->getNext();
            }
            current_node->setNext(key, value);
        }
    }

    void get(){
    }

    void remove(){
    }

private:
    // K key;
    // V value;
    MinhNode<K, V>** hash_table; 
    F hash_func;
};