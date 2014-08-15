
#include <stdio.h>


int main(int argc, char **argv)
{
int i;
int IntArray[4];  //Note mixed case (characters allowed in identifiers)

for (i=0;i<4; i++)  //Constant "4"  should use what instead??
    {
    IntArray[i]=10-i;
    }

for (i=0;i<4;i++)
    {
    printf("%d\n",IntArray[i]);
    printf("%d\n",*(IntArray+i));
    }
}


