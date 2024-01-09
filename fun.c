/* Function with memory leak */
#include <stdlib.h>
#include <stdio.h>

typedef struct Node {
    int *some_ptr;
} Node; 

Node* f()
{
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (!new_node) {
        free(new_node);
        exit(1);
    }
    new_node->some_ptr = (int *)malloc(sizeof(int)*10);
    if (!new_node) {
        free(new_node);
        exit(1);
    }
    int a = 5;
    new_node->some_ptr[0] = a;
    /* Do some work */
    
 
    /* Return without freeing ptr*/
    return new_node;
}

int main() {
    Node *ff = f();
    
    printf("Some command\n");
    printf("Some command\n");
    
    free(ff->some_ptr);
    free(ff);
    return 0;
}
