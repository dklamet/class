
#include <stdio.h>


#define FAN         0x1
#define MOTION      0x2
#define LIGHT       0x4
#define OPEN        0x8
#define POWER       0x10
#define CHARGE      0x20
#define EXPLODE     0x30


int controller (unsigned char cmd)
{
int returnval=1; //Fail
    if (cmd & FAN)
        {
        printf("Fan  ");
        returnval=1;
        }
    if (cmd & MOTION)
        {
        printf("Motion ");
        returnval=1;
        }
    if (cmd & LIGHT)
        {
        printf("Light ");
        returnval=1;
        }
    if (cmd & OPEN)
        {
        printf("Open ");
        returnval=1;
        } 
    if (cmd & POWER)
        {
        printf("Power ");
        returnval=1;
        } 
    if (cmd & CHARGE)
        {
        printf("Charge ");
        returnval=1;
        } 
    if (cmd & EXPLODE)
        {
        printf("Explode!");
        returnval=1;
        } 
    printf("\n");
return returnval;

}

int main(int argc, char **argv)
{
printf("First:\n");
controller(CHARGE|POWER);
printf("\n\nSecond:\n");
controller(OPEN|MOTION|LIGHT);
printf("\n\nThird:\n");
controller(EXPLODE|CHARGE);
}
