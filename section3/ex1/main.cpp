
#include <stdio.h>
#include "functions.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
int num;
char str[30];
printf("Enter a number\n");
fgets(str,29,stdin);
num=atoi(str);
PrintNumber(num);
}

