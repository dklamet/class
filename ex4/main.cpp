
#include <stdio.h>

#define LIST_SIZE 20

int main(int argc, char **argv)
{
int integer_list[LIST_SIZE];
int i;

for (i=0;i<LIST_SIZE;i++)
    {
    integer_list[i]=500-i;
    }

for (i=LIST_SIZE-1;i>=0;i--)
    {
    printf("%d\n",integer_list[i]);
    }

}


