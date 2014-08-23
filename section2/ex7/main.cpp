
#include <stdio.h>



int main(int argc, char **argv)
{

char str1[10];
char str2[10];

printf("Enter first string. ?\n");
gets(str1);

printf("Enter second stringstring. ?\n");
fgets(str2,10,stdin);

printf("You typed  \"%s\" and \"%s\"  \n",str1, str2);  //Why linefeed before final "?
}
