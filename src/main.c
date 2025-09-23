#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"
#include "../include/kernel_functions.h"



int main() {

    uint8_t width;

    uint8_t height;


    width = get_tile_map_width(0);

    height = get_tile_map_height(0);

    printf("default tile size:\nX = %d, Y = %d\n", width, height);

    set_tile_height(0b00000011, 0);

    set_tile_width(0b00000010, 0);

    width = get_tile_map_width(0);

    height = get_tile_map_height(0);

    printf("new tile size:\nX = %d, Y = %d\n", width, height);

    return 0;

}