
#include <stdio.h>

#define LIST_SIZE 20

void print_string(char str[],int size) //Why can't we just put sizeof in this function
{

int i;
for (i=0;i<size;i++)
    {
    printf("%c  %d\n",str[i],sizeof(str));
    }

}

int main(int argc, char **argv)
{
char str[]="This is a string"; //Addes a null (zero) terminator
char chararray[]={'t','h','e',' ','h','a','r','d',' ','w','a','y',0}; //doesn't
print_string(str,sizeof(str));
print_string(chararray,sizeof(chararray));
printf("%s\n",str);
printf("%s\n",chararray);
}


