#include <stdio.h>
#include <stdint.h>
#include <string.h>

#include "cbm.h"

#include "cx16.h"

#include "../include/video_functions.h"



int main() {

    char name[] = "Luke Richard Stanghelle";

    copy_data_vram((uint16_t)name, strlen(name), VERA_INC_2, 0x1b000);

    while(1){

    }

}