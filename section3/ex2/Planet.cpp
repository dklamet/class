#include <stdio.h>
#include <malloc.h>  //Why needed
#include <string.h>  //Why needed?
#include "Planet.h"  //Quotes " vs angle brackets <>


void Print(Planet *p)
{
printf("Planet: %s\n",p->Name);
printf("Mass: %u\n",p->mass);
printf("Diameter: %u\n",p->diameter);
}

int New(Planet** p) //Why a pointer?
{
    *p=(Planet*) malloc(sizeof(Planet));
    if (NULL==p)
        {
        return 1; //Non-zero (true) on fail
        }
    (*p)->Name[0]=0;
    (*p)->mass=0;
    (*p)->diameter=0;
    return 0;
}

void Delete(Planet** p)
{
    if (NULL==*p)
        {
        printf("Object pointer invalid\n");
        }
    else
        {
        free(*p);
        }
}

//Error checking??
void setName(Planet *p, char *name)
{
   strncpy(p->Name,name,NAME_SIZE); 
}

void setMass(Planet *p, unsigned int mass)
{
    p->mass=mass;
}
void setDiameter(Planet *p, unsigned int diameter)
{
    p->diameter=diameter;
}





