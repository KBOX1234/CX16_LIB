#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"
#include "../include/kernel_functions.h"



int main() {

    uint8_t key;

    while(1){
        key = getin();

        if(key == 'k') break;

        vpoke(key, 0x1b000);
    }

    return 0;

}