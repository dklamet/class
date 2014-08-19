#ifndef __draw_h
#define __draw_h

#include <X11/Xlib.h>

struct Point
{
int x,y;
};


void drawcircle(int x,int y,int radius, int color);
void drawline(Point a, Point b,int color);
void drawline(int x1,int y1,int x2,int y2,int color);
void drawpoint(int x,int y,int color);
void drawbigpoint(int x,int y, int color);
void drawmedpoint(int x,int y, int color);
void drawrect(int x,int y, int width, int height, int color);
void drawpoly(Point a, Point b, Point c, Point d, int color);
void init_graphics(int xsize, int ysize);
void clearwindow();
void flush();


#define BLACK 0
#define RED 1
#define ORANGE 2
#define YELLOW 3
#define GREEN 4
#define BLUE 5
#define INDIGO 6
#define VIOLET 7
#define WHITE 8

#define NUM_COLORS 9

extern char *draw_colors[];
extern Display *dpy;
extern Window win;




#endif
