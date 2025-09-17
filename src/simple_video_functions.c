#include "../include/video_functions.h"

void select_vera_memory_addr(unsigned long vram_addr){
    VERA.address = vram_addr & 0xFFFF;
    VERA.address_hi &= ~0x01;
    VERA.address_hi |= (vram_addr >> 16) & 0x01;
}

void set_addr_inc(uint8_t inc_value){
    VERA.address_hi = (VERA.address_hi & 0b00000111) | inc_value;
}

void copy_data_to_vram(uint16_t addr, uint16_t size, uint8_t skip, unsigned long vram_addr){
    uint16_t i;
    i = 0;

    select_vera_memory_addr(vram_addr);
    set_addr_inc(skip);

    while(i < size){
        VERA.data0 = *((uint8_t*)addr + i);

        i++;
    }
    
}

void copy_data_from_vram(uint16_t addr, uint16_t size, uint8_t skip, unsigned long vram_addr){
    uint16_t i;
    i = 0;

    select_vera_memory_addr(vram_addr);
    set_addr_inc(skip);

    while(i < size){
        *((uint8_t*)addr + i) = VERA.data0;

        i++;
    }
    
}