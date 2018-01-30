#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

int v, x[10], y[10], xt[10], yt[10], ch, tx, ty, sx, sy, r, i;

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(0.0,1.0,1.0);
	glMatrixMode(GL_PROTECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void setPixel()
{
        glClear(GL_COLOR_BUFFER_BIT);
        glPointSize(10.0);
        glBegin(GL_LINE_LOOP);
        for(i=0;i<v;i++)
        {
                glVertex2i(x[i], y[i]);
        }
        glEnd()
;
glBegin()}
