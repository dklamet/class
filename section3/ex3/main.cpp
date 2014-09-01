
#include <stdio.h>
#include <stdlib.h>

extern int ExternalVariable;  //Now we can see it
void ExternalFunction(int); //Only one, don't use a header file

void print1(int a)
{
    printf("Print1 %d\n",a);
}

void print2(int a)
{
    printf("Print2 %d\n",a);
}

void print3(int a)
{
    printf("Print3 %d\n",a);
}

int main(int argc, char **argv)
{
    void (*funcptrs[3])(int);
    int i,j;
    printf("External variable value=%d\n",ExternalVariable);
    ExternalFunction(22);
    printf("External variable value=%d\n",ExternalVariable);


    //Function pointers
    funcptrs[0]=print1;
    funcptrs[1]=print2;
    funcptrs[2]=print3;

    for (i=0;i<3;i++)
        {
        for (j=0;j<3;j++)
            {
            (*funcptrs[i])(i);
            }
        }

} 
