#include "../include/video_functions.h"

void select_vera_memory_addr(unsigned long vram_addr){
    VERA.address = vram_addr & 0xFFFF;
    VERA.address_hi &= ~0x01;
    VERA.address_hi |= (vram_addr >> 16) & 0x01;
}

void set_addr_inc(uint8_t inc_value){
    VERA.address_hi = (VERA.address_hi & 0b00000111) | inc_value;
}

void set_tile_color_depth(uint8_t depth, uint8_t layer){

    if(layer == 1){

        L1_CONFIG = L1_CONFIG & 0b00000011;

        L1_CONFIG = L1_CONFIG | depth;

        return;

    }

    L0_CONFIG = L0_CONFIG & 0b00000011;

    L0_CONFIG = L0_CONFIG | depth;

    
}

void set_tile_width(uint8_t width, uint8_t layer){
    if(layer == 1){
        L1_CONFIG = (L1_CONFIG & ~0b00110000) | ((width & 0x03) << 4);

        return;
    }

    L0_CONFIG = (L0_CONFIG & ~0b00110000) | ((width & 0x03) << 4);
    
}

void set_tile_height(uint8_t height, uint8_t layer){
    if(layer == 1){
        L1_CONFIG = (L1_CONFIG & ~0b11000000) | ((height & 0x03) << 6);

        return;
    }

    L0_CONFIG = (L0_CONFIG & ~0b11000000) | ((height & 0x03) << 6);
}

uint8_t get_tile_map_width(uint8_t layer) {
    uint8_t rtv;

    if(layer == 1) rtv = L1_CONFIG;
    else rtv = L0_CONFIG;

    rtv >>= 4;  

    rtv &= 0b00000011;  

    return rtv;
}

uint8_t get_tile_map_height(uint8_t layer) {
    uint8_t rtv;

    if(layer == 1) rtv = L1_CONFIG;
    else rtv = L0_CONFIG;

    rtv >>= 6;  

    rtv &= 0b00000011;  

    return rtv;
}