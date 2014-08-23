
#include <stdio.h>

int add1(int val)
{
    val += 1;    
    printf("In add1, val = %d\n",val);
    return val+1;
} 


int main(int argc, char **argv)
{
int a;
a=3;
while (a < 20)
    {
    printf("a is %d\n",a);
    a=add1(a);
    }
}

