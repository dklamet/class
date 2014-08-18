
#include <stdio.h>
#include <unistd.h>
#include <draw.h>

int main(int argc, char **argv)
{
init_graphics(500,500);

//drawcircle( 50,50,30,YELLOW);

//Define points
struct Point  p1={5,5};
Point  p2={70,5}; //C++ shortcut, don't need the "struct"
Point  p3={70,70}; 
Point  p4;  //Not initialized

//p4 not initialized, wet the members separately
p4.x=5;
p4.y=70;


Point *pp1,*pp2,*pp3,*pp4;

pp1=&p1;
pp2=&p2;
pp3=&p3;
pp4=&p4;



//Based on what we know, this is how we would access the elements::
(*pp1).x=5;
(*pp1).y=5;

//Element access, pointer style
pp2->x=70;
pp2->y=5;

pp3->x=70;
pp3->y=70;

pp4->x=5;
pp4->y=70;


drawline(*pp1,*pp2,YELLOW);
drawline(*pp2,*pp3,YELLOW);
drawline(*pp3,*pp4,YELLOW);
drawline(*pp4,*pp1,YELLOW);
flush();
sleep(8);

}

