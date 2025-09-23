#include "../include/kernel_functions.h"
#include <string.h>

#define ZERO_A (*(uint8_t*)0x0022)
#define ZERO_X (*(uint8_t*)0x0023)
#define ZERO_Y (*(uint8_t*)0x0024)

#define SETNAM ((void(*)(void))0xFFBD)

uint8_t basin(){
    asm("ldy #$00");

    //jump to BASIN subroutine
    asm("jsr $FFCF");
    asm("sta $0022");

    return ZERO_A;
}

unsigned long entropy_get(){

    //call entropy_get api
    asm("jsr $FECF");

    asm("sta $0022");
    asm("stx $0023");
    asm("sty $0024");

    //that extra missing byte
    asm("jsr $FECF");
    asm("sta $0025");

    return (unsigned long)ZERO_A;
}

uint8_t getin(){
    //call getin kernel api
    asm("jsr $FFE4");

}

void load_file(const char* fname, unsigned long addr, uint8_t ram_space){
    cbm_k_setnam(fname);

    cbm_k_setlfs(0, 8, 2);

    cbm_k_load(ram_space, addr);
}