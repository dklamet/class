
#include <stdio.h>


int main(int argc, char **argv)
{
int i;
int IntArray[4];  //Note mixed case (characters allowed in identifiers)

void  *voidptr;
void  *voidptr1;

for (i=0;i<4; i++)  //Constant "4"  should use what instead??
    {
    IntArray[i]=10-i;
    }

voidptr=(void *) &IntArray[0];
voidptr1=&IntArray; //What, no warning?
for (i=0;i<4;i++)
    {
    printf("%d\n", *((int *)voidptr+i));
    printf("%d\n", *((int *)voidptr1+i));
    printf("%d\n", *(int *)(voidptr1+i)); //???
    }


}


