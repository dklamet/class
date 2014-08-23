
#include <stdio.h>
#include <unistd.h>


int main(int argc, char **argv)
{
unsigned int value=0;  //Initialize and define
int i;

value=1;

for (i=0;i<sizeof(unsigned int)*4; i++)
    {
    printf("%04x\n",value);
    value=value<<1;
    usleep(100000);
    }

for (i=0;i<sizeof(unsigned int)*8; i++)
    {
    unsigned int allones=0xffffffff;
    printf("%08X\n",allones & ~(1<<i));
    usleep(500000);
    }
}

