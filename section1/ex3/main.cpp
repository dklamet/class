
#include <stdio.h>

void add1(int val)
{
   val= val+1;
   printf("In add1, val = %d\n",a);
} 


int main(int argc, char **argv)
{
int a;
a=3;
while (a < 20)
    {
    printf("a is %d\n",a);
    add1(a);
    }
}

