
#include <stdio.h>


int globalvar=0; //Global variable

void anotherfunction()
{
    int a=6;  //A different a than below
    int b=12;
    int c=22;
}



void function(int val)
{
    int a;
    if (val>7)
        {
        a=val;
        }
    printf("val is %d\n",a);
}


int main(int argc, char **argv)
{
function(9);
anotherfunction(); //What happends if we take this out.
function(3);
}

