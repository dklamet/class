// Written by Ch. Tronche (http://tronche.lri.fr:8000/)
// Copyright by the author. This is unmaintained, no-warranty free software. 
// Please use freely. It is appreciated (but by no means mandatory) to
// acknowledge the author's contribution. Thank you.
// Started on Thu Jun 26 23:29:03 1997

//
// Xlib tutorial: 2nd program
// Make a window appear on the screen and draw a line inside.
// If you don't understand this program, go to
// http://tronche.lri.fr:8000/gui/x/xlib-tutorial/2nd-program-anatomy.html
//

#include <X11/Xlib.h> // Every Xlib program must include this
#include <assert.h>   // I include this to test return values the lazy way
#include <unistd.h>   // So we got the profile for 10 seconds
#include <stdlib.h>
#include <time.h>
#include "draw.h"

#define NIL (0)       // A name for the void pointer

//Global variables for display structures
Display *dpy;
Colormap cmap;
XGCValues gcval;
GC colorgcs[9];
Window win;

char *draw_colors[NUM_COLORS]={"black","red","orange","yellow","green","blue","indigo","violet","white"};

int centerx, centery;
int width;
int height;
#define mapy(y) centery-y
#define mapx(x) x+centerx
//***************************************************************
void init_graphics(int xsize, int ysize)
{
dpy = XOpenDisplay(NIL);
assert(dpy);

// Get some colors

int blackColor = BlackPixel(dpy, DefaultScreen(dpy));
int whiteColor = WhitePixel(dpy, DefaultScreen(dpy));
centerx=xsize/2;
centery=ysize/2;
width=xsize;
height=ysize;
// Create the window
win = XCreateSimpleWindow(dpy, DefaultRootWindow(dpy), 0, 0, 
				     xsize, ysize, 0, whiteColor, blackColor);
// We want to get MapNotify events

XSelectInput(dpy, win, StructureNotifyMask|KeyPressMask);

// "Map" the window (that is, make it appear on the screen)

XMapWindow(dpy, win);

// Create a "Graphics Context"

GC gc = XCreateGC(dpy, win, 0, NIL);

// Tell the GC we draw using the white color

  cmap = DefaultColormap (dpy, DefaultScreen(dpy));
  XSetForeground(dpy, gc, whiteColor);

XColor blackcolor,ignore;
XAllocNamedColor(dpy, cmap, draw_colors[0], &blackcolor, &ignore);
//colorgcs[0]=XCreateGC(dpy,win,0,0);
colorgcs[0]=XCreateGC(dpy,win,GCForeground|GCBackground,&gcval);
XSetForeground(dpy,colorgcs[0],blackcolor.pixel);
XSetBackground(dpy,colorgcs[0],blackcolor.pixel);
int i;
for(i=1;i<9;i++)
	{
	XColor color;
	XAllocNamedColor(dpy, cmap, draw_colors[i], &color, &ignore);
	colorgcs[i]=XCreateGC(dpy,win,GCForeground|GCBackground,&gcval);
	XSetForeground(dpy,colorgcs[i],color.pixel);
	XSetBackground(dpy,colorgcs[i],blackcolor.pixel);
	}	
	



// Wait for the MapNotify event
for(;;) 
	{
		XEvent e;
		XNextEvent(dpy, &e);
		if (e.type == MapNotify)
		  break;
    }



}

void drawline(Point a, Point b,int color)
{
	XDrawLine(dpy, win, colorgcs[color],mapx(a.x), mapy(a.y), mapx(b.x),mapy(b.y));
}

void drawline(int x1,int y1,int x2,int y2,int color)
{
		XDrawLine(dpy, win, colorgcs[color], mapx(x1), mapy(y1),mapx(x2), mapy(y2));
}

void drawcircle(int x,int y,int radius, int color)
{
XDrawArc(dpy,win,colorgcs[color], mapx(x)-radius, mapy(y)-radius,
                     2*radius, 2*radius,0,360*64);
}

void drawpoint(int x,int y, int color)
{
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y));
}

void drawbigpoint(int x,int y, int color)
{
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y));
XDrawPoint (dpy,win,colorgcs[color], mapx(x)+1, mapy(y)-1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x)+1, mapy(y));
XDrawPoint (dpy,win,colorgcs[color], mapx(x)+1, mapy(y)+1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y)+1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y)-1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x)-1, mapy(y)-1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x)-1, mapy(y));
XDrawPoint (dpy,win,colorgcs[color], mapx(x)-1, mapy(y)+1);
}

void drawmedpoint(int x,int y, int color)
{
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y));
XDrawPoint (dpy,win,colorgcs[color], mapx(x)+1, mapy(y)-1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x)+1, mapy(y)+1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y)+1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x), mapy(y)-1);
XDrawPoint (dpy,win,colorgcs[color], mapx(x)-1, mapy(y)-1);
}
void flush()
{
XFlush(dpy);
}

void drawrect(int x,int y, int width, int height, int color)
{
XDrawRectangle(dpy,win,colorgcs[color], mapx(x), mapy(y),width, height);
}

void drawpoly(Point a, Point b, Point c, Point d,int color)
{
drawline (mapx(a.x),mapy(a.y),mapx(b.x),mapy(b.y),color);
drawline (mapx(b.x),mapy(b.y),mapx(c.x),mapy(c.y),color);
drawline (mapx(c.x),mapy(c.y),mapx(d.x),mapy(d.y),color);
drawline (mapx(d.x),mapy(d.y),mapx(a.x),mapy(a.y),color);
}


void clearwindow()
{
    XClearWindow(dpy,win);
}
