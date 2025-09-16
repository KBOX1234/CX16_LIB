#include "cx16.h"

#include <stdint.h>

#include <stdio.h>

void select_vera_memory_addr(unsigned long vram_addr);

void set_addr_inc(uint8_t inc_value);

void copy_data_vram(uint16_t addr, uint16_t size, uint8_t skip, unsigned long vram_addr);