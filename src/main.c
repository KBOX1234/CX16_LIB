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
unsigned char *filename = "tiles.bin";

void main() {    
    // Note we need a `short` here because there are more than 255 tiles
    unsigned short i;
    
    // Turn on Color Depth 3 - 8 bpp
    set_tile_color_depth(0b11, 1);

    // 16x16 pixel tiles
    //VERA.layer1.tilebase |= 0b11;

    load_file(filename, tileBaseAddr, 3);

    vram_memset(mapBaseAddr, MAPBASE_TILE_COUNT, VERA_INC_1, 0);

    videomode(VIDEOMODE_32x25);

    while(1);

}