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
    unsigned hash;
    int value; 
    struct Node* next;
} Node_t;

typedef struct {
    Node_t **buckets;
    // Node_t **buckets[TABLE_SIZE];
} RandomizedSet;

int hash_fun(int key) {
    unsigned u_key  = (unsigned) key;
    u_key = ((u_key >> 16) ^ u_key) * 0x45d9f3b;
    u_key = ((u_key >> 16) ^ u_key) * 0x45d9f3b;
    u_key = (u_key >> 16) ^ u_key;
    return u_key % TABLE_SIZE;
}

Node_t *make_node(int val, unsigned hash) {
    Node_t *new_node = (Node_t *)malloc(sizeof(Node_t));
    new_node->value = val;
    new_node->hash = hash;
    new_node->next = NULL;
    return new_node;  
} 

/*  Hash table operating functions   */

RandomizedSet *randomizedSetCreate() {
    RandomizedSet map_t = {
        .buckets = (Node_t **)calloc(TABLE_SIZE, sizeof(Node_t *))
        // .buckets = (Node_t **)malloc(TABLE_SIZE * sizeof(Node_t *))
        // .buckets = {NULL}
    };
    printf("%d \n", sizeof(Node_t *));
    RandomizedSet *map_ptr = &map_t;
    Node_t sample_node = {.hash = 12345, .value = 3, .next = NULL};
    // for (int i = 0; i < TABLE_SIZE; i++) {
    //     // map_ptr->buckets[i] = sample_node;
    //     printf("%d \n", map_ptr->buckets[i]);
    // }
    map_ptr->buckets[0] = &sample_node;
    return map_ptr;
}

bool randomizedSetInsert(RandomizedSet *obj, int val) {
    unsigned hash_val = hash_fun(val);
    Node_t *node = make_node(val, hash_val);
    Node_t *current_node = obj->buckets[hash_val];

    if (!current_node) { 
        current_node = node;
    } else {
        while (current_node != NULL) {
            printf("Loop \n");
            if (current_node->value == val) {
                return false;
            } 
            current_node = current_node->next;
        }
        current_node = node; 
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
        printf("current bucket: %d \n", obj->buckets[i]);
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
    printf("What's wrong? \n");
    RandomizedSet* obj = randomizedSetCreate();
    printf("What's wrong? \n");
    // bool param_1 = randomizedSetInsert(obj, 1);
    // bool param_2 = randomizedSetInsert(obj, 1);
    // printf("Can insert (?): %d \n", param_2);
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

// typedef struct {
//     int tyre;
//     char brand[20];  
// } Car;

// int main () {
//     // Car *car1 = (Car *)malloc(20*sizeof(Car));
//     Car **car1[20] = {NULL};
//     Car **car2 = (Car **)calloc(20, sizeof(Car*));
//     printf("%d; %d", sizeof(car1), sizeof(car2));
//     // Car actual_obj = {.tyre = 20};
//     // car1 = &actual_obj;
//     // car1->tyre = 30;
//     // printf("%d \n", car1->tyre);
// }