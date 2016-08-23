
#include <stdio.h>


int main(int argc, char **argv)
{

int intvar=7;  //Define and intialize 

int *intvarpointer=&intvar;   


//Note the pointer address is printed in hex
printf("%p  points to %d\n",intvarpointer, *intvarpointer);

*intvarpointer=22;  //And we can change the value we're pointing to
printf("%p  points to %d --same memory location, different value\n",intvarpointer, *intvarpointer);
printf("intvar is also %d\n",intvar);
}


