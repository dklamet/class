
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <draw.h>
#include <malloc.h>
#include <time.h>

#define XSIZE  300 
#define YSIZE  300
#define DELAY  75   //Msec
#define DYNAMIC_MEMORY  
#define NUM_POINTS 300 



int getRandomInt(int maxval) //Why can't we just put sizeof in this function
{
    return rand()%(maxval+1);

}



int main(int argc, char **argv)
{


#ifdef DYNAMIC_MEMORY
Point *pts;
pts=(Point *) malloc(sizeof(Point)*NUM_POINTS);
#else
Point pts[NUM_POINTS];
#endif

int i,x,y,deltax, deltay;

srand((unsigned int) time(NULL)%39283);
deltax=getRandomInt(XSIZE/3);
deltay=getRandomInt(YSIZE/3);
x=5;
y=5;

for (i=0;i<NUM_POINTS;i++)
    {
    deltax=getRandomInt(XSIZE/3)-XSIZE/(3*2); //What does this do?
    deltay=getRandomInt(YSIZE/3)-YSIZE/(3*2);
    if ((x+deltax) >XSIZE/2  || (x+deltax) < 0)
        {
        deltax=-deltax;
        }
    
    if ((y+deltay) >YSIZE/2 || (y+deltay)<0)
        {
        deltay=-deltay;
        }
    x+=deltax;
    y+=deltay;
    pts[i].x=x;
    pts[i].y=y;
    }

init_graphics(500,500);

//drawcircle( 50,50,30,YELLOW);

//Define points
for (i=0;i<NUM_POINTS-1;i++)
    {
    drawline(pts[i],pts[i-1],i%9); 
    printf("%d %d %d\n",pts[i].x, pts[i].y, i%9);
    flush();
    usleep(DELAY*1000);
    }

sleep(10);

#ifdef DYNAMIC_MEMORY
free(pts);
#endif
//we're exiting
}

