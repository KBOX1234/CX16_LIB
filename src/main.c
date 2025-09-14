#include <stdio.h>
#include <stdint.h>

unsigned int larg;
int i;

int main() {

    larg = 2;

    for(i = 0; i < 15; i++){
        i = i * 2;
    }

    printf("big num: %d\n", larg);

    return 0;

}