#include "../include/kernel_functions.h"

#define ASM_RTV (*(unsigned long*)0x0022)

uint8_t basin(){
    asm("ldy #$00");

    //jump to BASIN subroutine
    asm("jsr $FFCF");
    asm("sta $0022");

    return ASM_RTV;
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

    return (unsigned long)ASM_RTV;
}

uint8_t getin(){

    //call getin kernel api
    asm("jsr $FFE4");

}