#include <stdio.h>

struct vehicle {
    int plate;
    int model1;
    int model2;

};

int main () {
    struct vehicle Car = {
        .plate = 1,
        .model2 = 2,
        .model1 = 3
    };

}