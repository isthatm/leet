/*
    Problem 380. Insert Delete GetRandom O(1)
    In this problem the value is the key and vice versa
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define TABLE_SIZE 127

typedef struct {
    unsigned value;
    int hash;
    struct Node* next;
} Node;

typedef struct {
    Node **buckets;
} RandomizedSet;

int hash_fun(int key) {
    unsigned u_key  = (unsigned) key;
    u_key = ((u_key >> 16) ^ u_key) * 0x45d9f3b;
    u_key = ((u_key >> 16) ^ u_key) * 0x45d9f3b;
    u_key = (u_key >> 16) ^ u_key;
    return u_key % TABLE_SIZE;
}

RandomizedSet *randomizedSetCreate() {
    RandomizedSet *map_t;
    map_t->buckets = (Node **)calloc(TABLE_SIZE, sizeof(Node *));
    return map_t;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    
}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    
}

void randomizedSetFree(RandomizedSet *obj) {
    // TODO: Free the nodes on the linked lists also
    free(obj);
}

int main() {
    RandomizedSet* obj = randomizedSetCreate();
    randomizedSetFree(obj);
}

/**
 * Your RandomizedSet struct will be instantiated and called as such:
 * RandomizedSet* obj = randomizedSetCreate();
 * bool param_1 = randomizedSetInsert(obj, val);
 
 * bool param_2 = randomizedSetRemove(obj, val);
 
 * int param_3 = randomizedSetGetRandom(obj);
 
 * randomizedSetFree(obj);
*/