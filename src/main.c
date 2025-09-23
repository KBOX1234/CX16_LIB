#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"
#include "../include/kernel_functions.h"



int main() {

    uint16_t addr;

    char* string;

    EMULATOR.debug = true;

    addr = 0x1667;

    RAM_BANK = 1;

    printf("crash test\n");

    f_load_to_ram("test.t", addr);

    string = (char*)addr;

    RAM_BANK = 1;

    printf("string: %s\n", (char*)addr + 1);

    printf("yes\n");

    return 0;

}