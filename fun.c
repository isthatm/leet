#include <stdio.h>
#include <string.h>
#include <pthread.h>
#include <windows.h>

// Global variables:
volatile int glob = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; // Mutex initialization

int a = 2805;

void* foo(void* p) {
    // Print value received as argument:
    for (int i = 0; i < 8; i++) {
        printf("%d. IN THREAD \n", i);
        if (i == 3) {
            pthread_mutex_lock(&mutex); // Lock mutex before modifying glob
            glob = 1;
            pthread_mutex_unlock(&mutex); // Unlock mutex after modifying glob
        }
        Sleep(1000);
    }
    // Return reference to global variable:
    pthread_exit(&a);
}

int main(void) {
    // Declare variable for thread's ID:
    pthread_t id;
    int j = 10;
    pthread_create(&id, NULL, foo, &j);
    while (1) {
        pthread_mutex_lock(&mutex); // Lock mutex before accessing glob
        if (glob) {
            pthread_mutex_unlock(&mutex); // Unlock mutex if glob is set
            break; // Exit loop if glob is set
        }
        pthread_mutex_unlock(&mutex); // Unlock mutex before sleeping
        printf("I'm stuck. \n");
        Sleep(1000); // Sleep for 1 second
    }
    printf("I'm out. \n");
    int* ptr;

    // Wait for foo() and retrieve value in ptr;
    pthread_join(id, (void**)&ptr);
    printf("Continued being stuck \n");
    printf("Value received by parent from child: %d\n", *ptr); // Print the value
}