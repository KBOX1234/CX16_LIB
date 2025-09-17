#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"



int main() {

    char name[] = "Luke Richard Stanghelle";

    char new_tile[8] = {
        0b01010101,
        0b10101010,
        0b01010101,
        0b10101010,
        0b01010101,
        0b10101010,
        0b01010101,
        0b10101010
    };

    char name2[200];

    copy_data_to_vram((uint16_t)name, strlen(name), VERA_INC_2, 0x1b000);

    copy_data_from_vram((uint16_t)name2, strlen(name), VERA_INC_2, 0x1b000);

    copy_data_to_vram((uint16_t)new_tile, 8, VERA_INC_1, 0x1f000);



    name2[strlen(name) + 1] = '\0';

    printf("@%s\n", name2);

    while(1){

    }

}