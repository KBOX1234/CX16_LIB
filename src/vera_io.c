#include "../include/video_functions.h"

void select_vera_memory_addr(unsigned long vram_addr){
    VERA.address = vram_addr & 0xFFFF;
    VERA.address_hi &= ~0x01;
    VERA.address_hi |= (vram_addr >> 16) & 0x01;
}

void set_addr_inc(uint8_t inc_value){
    VERA.address_hi = (VERA.address_hi & 0b00000111) | inc_value;
}

void set_tile_color_depth(uint8_t depth){
    *(uint8_t *)0x9F34 = *(uint8_t *)0x9F34 & 0b11000011;

    *(uint8_t *)0x9F34 = *(uint8_t *)0x9F34 | depth;
}