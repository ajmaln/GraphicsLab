/*DDA Algorithm
  S8 C.S.E*/

#include<GL/glut.h>
#include<stdio.h>

int step,i;
float dx,dy,x,y,x1,x2,y1,y2,xi,yi;

void init(void)
{
   glClearColor(0.0,0.0,0.0,0.0);
   glColor3f(1.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void DDA()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(1.0);
   glBegin(GL_POINTS);
   x=x1;
   y=y1;
   dx=x2-x1;
   dy=y2-y1;
   if(dx>dy)
        step=dx;
   else
        step=dy;
   xi=dx/step;
   yi=dy/step;
   glVertex2i(x,y);
   for(i=1;i<step;i++)
   {
      x+=xi;
      y+=yi;
      glVertex2i(x,y);
   }
   glEnd();
   glFlush();
}

int main(int argc,char **argv)
{
   printf("Enter the coordinates");
   scanf("%f%f%f%f",&x1,&y1,&x2,&y2);
   glutInit(&argc,argv);
   glutInitWindowPosition(20,20);
   glutInitWindowSize(200,200);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutCreateWindow("HAI");
   init();
   glutDisplayFunc(DDA);
   glutMainLoop();
   return 0;
}                   

