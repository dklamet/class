
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIST_SIZE 20

void getRandomIntArray(int *array, int size,int maxval) //Why can't we just put sizeof in this function
{
int i;
srand((unsigned int) time(NULL)%39283);

for (i=0;i<size;i++)
    {
    array[i]=rand()%(maxval+1);
    }

}

int main(int argc, char **argv)
{
int array[30];
int i;

getRandomIntArray(array,30,8);

for (i=0;i<30;i++)
    {
    printf("%d\n",array[i]);
    }

}

