#include "../include/video_functions.h"

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

void vram_memset(unsigned long vram_addr, uint16_t size, uint8_t skip, uint8_t val){
    uint16_t i;
    select_vera_memory_addr(vram_addr);

    set_addr_inc(skip);


    i = 0;

    while(i < size){
        VERA.data0 = val;

        i++;
    }
}