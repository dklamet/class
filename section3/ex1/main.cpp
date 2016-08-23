
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main(int argc, char **argv)
{

#define byte unsigned char


    byte  a;
    a=1;   ///00000001
    a=2;   ///00000010
    a=3;   ///00000011
    a=4;   ///00000100
    a=8;   ///00001000
    a=9;   ///00001001
    a=128; ///10000000
    a=255; ///11111111

    a=0x1; ///00000001
    a=0x9; ///00001001
    a=0xa; ///00001010
    a=0xb; ///00001011
    a=0xc; ///00001100
    a=0xd; ///00001101
    a=0xe; ///00001110
    a=0xf; ///00001111

    a=0x10;///00010000
    a=0x11;///00010001
    a=0x44;///0100 0100
    a=0x45;///0100 0101

    a=xxx00000001; //=1

    int b=0x1;

    |
    &
    ^
    <<
    a= 0x03; 00011011 ;0x1b
    b= 0x02; 00001110 ;0x0e

#define FOPEN 0x1           //00001
#define FCLOSE 0x2          //00010
#define FAPPEND 0x4         //00100
#define FREADONLY 0x8       //01000
#define FEXCLU    0x10      //10000




}
