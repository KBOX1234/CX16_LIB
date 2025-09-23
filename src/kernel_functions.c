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

void setnam(const char* fname){
    ZERO_A = (uint8_t)strlen(fname);
    ZERO_X = (uint8_t)((uint16_t)fname & 0xFF);
    ZERO_Y = (uint8_t)(((uint16_t)fname >> 8) & 0xFF);

    asm("lda $0022");
    asm("ldx $0023");
    asm("ldy $0024");
    asm("jsr $ffbd");

}

void setlfs(uint8_t file_num, uint8_t device_number, uint8_t secondary_address){
    ZERO_A = file_num;
    ZERO_X = device_number;
    ZERO_Y = secondary_address;

    asm("lda $0022");
    asm("ldx $0023");
    asm("ldy $0024");
    asm("jsr $ffba");

    
}

void f_load_to_ram(const char* fname, uint16_t addr){

    //SETNAM
    uint8_t lo;
    uint8_t hi;

    setnam(fname);

    setlfs(3, 0x08, 0);


    //LOAD
    lo = addr & 0xFF;
    hi = (addr >> 8) & 0xFF;
    ZERO_X = lo;
    ZERO_Y = hi;

    asm("lda #$01");
    asm("ldx $0023");
    asm("ldy $0024");

    //call load
    asm("jsr $FFD5");

}