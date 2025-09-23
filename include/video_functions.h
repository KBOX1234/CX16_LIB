#include "cx16.h"

#include <stdint.h>

#include <stdio.h>

#include <stdbool.h>

#define L0_CONFIG *(uint8_t *)0x9F2D

#define L1_CONFIG *(uint8_t *)0x9F34

//io
void select_vera_memory_addr(unsigned long vram_addr);

void set_addr_inc(uint8_t inc_value);

//please read: 
void set_tile_color_depth(uint8_t depth, uint8_t layer);

//does not take arbitrary width pleas see: https://github.com/mwiedmann/cx16CodingInC/blob/main/Chapter06-Tiles/README.md
void set_tile_width(uint8_t width, uint8_t layer);

//please see: https://github.com/mwiedmann/cx16CodingInC/blob/main/Chapter06-Tiles/README.md
void set_tile_height(uint8_t height, uint8_t layer);

uint8_t get_tile_map_width(uint8_t layer);

uint8_t get_tile_map_height(uint8_t layer);

// data
void copy_data_to_vram(uint16_t addr, uint16_t size, uint8_t skip, unsigned long vram_addr);

void copy_data_from_vram(uint16_t addr, uint16_t size, uint8_t skip, unsigned long vram_addr);

void vram_memset(unsigned long vram_addr, uint16_t size, uint8_t skip, uint8_t val);

