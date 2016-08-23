
#include <stdio.h>
#include <stdlib.h>

#define HIGH_NIB_MASK 0xf0
#define LOW_NIB_MASK 0x0f
#define NIBBLE_SHIFT 4

//Bitwise operators

int main(int argc, char **argv)
{
    unsigned int value;

    unsigned int lownibble;
    unsigned int highnibble;
    value=0x33;

    lownibble=(value & LOW_NIB_MASK);
    printf("Low nibble is %02x \n",lownibble);

    highnibble=(value &  HIGH_NIB_MASK) >> NIBBLE_SHIFT;

    printf("High nibble happens to also be %02x\n",highnibble);

    value=value|0xc0;  //Set the high two bits of the high nibble (or with 1100 0000)
    highnibble=(value &  HIGH_NIB_MASK) >> NIBBLE_SHIFT;
    printf("Value is now %02x, high nibble is %02x\n",value,highnibble);
    

} 
