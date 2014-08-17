
#include <stdio.h>
#include <string.h>  //More library functions

//void passbyref(int *a, int b, char str[])
void passbyref(int *a, int b, char *str)
{
printf("*a = %d, b=%d %s\n",*a,b,str); //Note format %s for strin
*a=37;
str[6]='x';

printf("set *a = %d, b=%d\n",*a,b);
}


int main(int argc, char **argv)
{

//Note single chars use single quote '
//Strings use double quotes "
//
char *s="This is a string";

s[3]='b';
int intvar=7;  //Define and intialize 

passbyref(&intvar,22,&s[0]);
printf("*a(intvar) = %d, b=%d(constant) %s\n",intvar,99999,&s[0]);

}


