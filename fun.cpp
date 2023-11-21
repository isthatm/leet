#include <iostream>
using namespace std;

const int TABLE_SIZE = 100;
// template <typename K, typename V>
class MinhNode{
public:
    MinhNode(int key, int value): key(key), value(value), next(NULL){}

    MinhNode* getNext(){
        return next;
    }

    int getValue(){
        return value;
    }

    int getKey(){
        return key;
    }

    void setNew(int key, int value){
        next = new MinhNode(key, value); 
    }

    void setNext(MinhNode* next_node){
        next = next_node;
    }

private:
    int key;
    int value;
    MinhNode* next;
};

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


// template <typename K, typename V, typename F>
class MyHashMap{
public:
    MyHashMap(){
        hash_table = new MinhNode* [TABLE_SIZE](); // A dynamic array of pointers to NULL
    }

    ~MyHashMap(){
        MinhNode* current_node = NULL;
        MinhNode* prev_node = NULL;

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

    void put(int key, int value){
        // allocate the values to buckets on the heap
        auto hash_value = hash_func(key);
        MinhNode* current_node = hash_table[hash_value];

        if (!hash_table[hash_value]){// No key in this bucket
            hash_table[hash_value] = new MinhNode (key, value);
        } else{// put it at the end of the list in this bucket
            while (true){
                // cout << current_node->getValue() << endl;
                if (!(current_node->getNext())){
                    break;
                }
                current_node = current_node->getNext();
            }
            current_node->setNew(key, value);
        }
    }

    int get(int key){
        auto hash_value = hash_func(key);
        MinhNode* current_node = hash_table[hash_value];
        int value = -1;
        if (!current_node){
            // value = "Not found";
            return value;
        } else{
            while(current_node != NULL){
                if (key == current_node->getKey()){
                    cout << "INN" << endl;
                    value = current_node->getValue();
                    break;
                    // return value;
                }
                current_node = current_node->getNext();
            }
            return value;
        }
    }

    void remove(int key){
        auto hash_value = hash_func(key);
        MinhNode* current_node = hash_table[hash_value];
        MinhNode* prev_node = NULL;

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
    MinhNode** hash_table; 
    int_hash hash_func;
};

int main(){
    MyHashMap* obj = new MyHashMap();
    obj->put(1,1);
    obj->put(2,2);
    

    int param_2 = obj->get(1);
    param_2 = obj->get(3);
    obj->put(2,1);
    param_2 = obj->get(2);
    cout << param_2 << endl;
    obj->remove(2);
    param_2 = obj->get(2);
}