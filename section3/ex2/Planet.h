
#ifndef __functions_h
#define __functions_h

#define NAME_SIZE 30
typedef struct
{
    char Name[NAME_SIZE];              //What is inconsistent about the members
    unsigned int mass;
    unsigned int diameter;
}Planet;

void Print(Planet* p);
int New(Planet** p); //Why a pointer?
void Delete(Planet** p);
void setName(Planet* p, char *name);
void setMass(Planet* p, unsigned int mass);
void setDiameter(Planet* p, unsigned int mass);

#endif


