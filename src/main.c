#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"
#include "../include/kernel_functions.h"

#define MAPBASE_TILE_COUNT 128*64

// Our default Tile and Map Base addresses
unsigned long tileBaseAddr = 0x1F000;
unsigned long mapBaseAddr = 0x1B000;
const char *filename = "tiles.bin";

void main() {    

    uint8_t input;
    

    set_tile_map_color_depth(0b11, 1);

    // 16x16 pixel tiles
    //VERA.layer1.tilebase |= 0b11;

    set_tile_map_height(0b00, 1);
    set_tile_map_width(0b00, 1);

    videomode(VIDEOMODE_20x15);

    load_file(filename, tileBaseAddr, 3);

    vram_memset(mapBaseAddr, MAPBASE_TILE_COUNT, VERA_INC_1, 0);

    while(1){
        input = getin();

        if(input == 'w'){
            VERA.layer1.vscroll--;
        }
        if(input == 's'){
            VERA.layer1.vscroll++;
        }
        if(input == 'a'){
            VERA.layer1.hscroll--;
        }
        if(input == 'D'){
            VERA.layer0.hscroll++;
        }
    }

}