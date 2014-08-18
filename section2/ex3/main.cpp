
#include <stdio.h>
#include <unistd.h>
#include <draw.h>
#include <malloc.h>


int main(int argc, char **argv)
{
init_graphics(500,500);

//drawcircle( 50,50,30,YELLOW);

//Define points
Point*  pp1; //* can be either Point* pp1
Point*  pp2; //or Point *pp2
Point*  pp3; //Former is preferred
Point*  pp4;


pp1=(Point*)malloc(sizeof(Point));
pp2=(Point*)malloc(sizeof(Point));
pp3=(Point*)malloc(sizeof(Point));
pp4=(Point*)malloc(sizeof(Point));



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


//Free it, but really don't need to since
//we're exiting
free (pp1);
free (pp2);
free (pp3);
free (pp4);
}

