/*
    Problem 380. Insert Delete GetRandom O(1)
    In this problem the value is the key and vice versa
    TODO: 
    - Free the nodes on the linked lists also
    - Create a make_node function
    - Create an aray to store filled buckets
    - Investigate what does bool in insert means?
*/
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

#define TABLE_SIZE 127


typedef struct Node {
    int value;
    unsigned hash;
    struct Node* next;
} Node_t;

typedef struct {
    Node_t **buckets;
} RandomizedSet;

int hash_fun(int key) {
    unsigned u_key  = (unsigned) key;
    u_key = ((u_key >> 16) ^ u_key) * 0x45d9f3b;
    u_key = ((u_key >> 16) ^ u_key) * 0x45d9f3b;
    u_key = (u_key >> 16) ^ u_key;
    return u_key % TABLE_SIZE;
}

Node_t *make_node(int val, unsigned hash) {
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t *));
    new_node->value = val;
    new_node->hash = hash;
    new_node->next = NULL;
    return new_node;  
} 

/*  Hash table operating functions   */

RandomizedSet *randomizedSetCreate() {
    RandomizedSet *map_t;
    map_t->buckets = (Node_t **)calloc(TABLE_SIZE, sizeof(Node_t *));
    return map_t;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    unsigned hash_val = hash_fun(val);
    Node_t *node = make_node(val, hash_val);
    Node_t *current_node = obj->buckets[hash_val];

    if (!current_node) { 
        current_node = node;
    } else {
        while (current_node->next != NULL) {
            current_node = current_node->next;
        }
        current_node->next = node; 
    }
    return true;

}

bool randomizedSetRemove(RandomizedSet *obj, int val) {
    
}

int randomizedSetGetRandom(RandomizedSet *obj) {
    
}

void randomizedSetFree(RandomizedSet *obj) {
    Node_t *cur_node = NULL;
    Node_t *prev_node = NULL; 

    for (int i = 0; i < TABLE_SIZE; i++) {
        cur_node = obj->buckets[i];
        if (cur_node != NULL) {
            prev_node = cur_node;
            cur_node = cur_node->next;
            free (prev_node);
        }
    }
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