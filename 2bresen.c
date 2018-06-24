/*BRESENHAM'S LINE DRAWING ALGORITHM
  S8 CSE*/
  
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>

float dx,dy,x0,y_0,x1,y_1,x,y,p;

void init(void)
{
   glClearColor(0.0,0.0,0.0,0.0);
   glColor3f(1.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void BRESENHAMS()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(1.0);
   glBegin(GL_POINTS);
   x=x0;
   y=y_0;
   glVertex2i(x,y);
   dx=abs(x1-x0);
   dy=abs(y_1-y_0);
   p=(2*dy)-dx;
   for(int i=0;i<dx;i++)
   {
      if(p<0)
      {
         glVertex2i(++x,y);
         p=p+(2*dy);
      }
      else
      {
         glVertex2i(++x,++y);
         p=p+(2*dy)-(2*dx);
      }
   }
   glEnd();
   glFlush();
}

int main(int argc,char **argv)
{
   printf("Enter the coordinates");
   scanf("%f%f%f%f",&x0,&y_0,&x1,&y_1);
   glutInit(&argc,argv);
   glutInitWindowPosition(20,20);
   glutInitWindowSize(200,200);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutCreateWindow("HAI");
   init();
   glutDisplayFunc(BRESENHAMS);
   glutMainLoop();
   return 0;
}                  
