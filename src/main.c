#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"



int main() {

    char name[] = "Luke Richard Stanghelle@";

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

    uint8_t color;

    size_t size;

    copy_data_to_vram((uint16_t)name, strlen(name), VERA_INC_2, 0x1b000);

    copy_data_from_vram((uint16_t)name2, strlen(name), VERA_INC_2, 0x1b000);

    copy_data_to_vram((uint16_t)new_tile, 8, VERA_INC_1, 0x1f000);



    name2[strlen(name) + 1] = '\0';

    printf("@%s\n", name2);

    color = 0;

    size = strlen(name);

    while(1){

        if(color == 255) break;

        color++;

        vram_memset(0x1b001, size, VERA_INC_2, color);
    }

    set_tile_color_depth(0b11);

    while(1);

}