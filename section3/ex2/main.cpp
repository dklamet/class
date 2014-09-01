
#include <stdio.h>
#include "Planet.h"
#include <stdlib.h>

int main(int argc, char **argv)
{
Planet *p;

New(&p);

Print(p);
setName(p,(char *) "Jupiter");
Print(p);
setMass(p,27);
Print(p);
setDiameter(p,27);
Print(p);
} 
