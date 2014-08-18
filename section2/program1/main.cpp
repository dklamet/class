
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


//Draw square, slowly

//Bottom
drawline(5,5,70,5,YELLOW);
flush();
sleep(2);
drawline(70,5 ,70,70,YELLOW);
flush();
sleep(2);

//Same function name, different arguments C++ only
//C would require different name
drawline(p3,p4,YELLOW); flush();
sleep(2);
drawline(p4,p1,YELLOW);
flush();

sleep(8);

}

