#include<stdio.h>
#include<GL/glut.h>

float dx,dy,x,y,x1,y1,x2,y2,p;

void init(){
   glClearColor(0.0,0.0,0.0,0.0);
   glColor3f(1.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void DDA()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(3.0);
   glBegin(GL_POINTS);
   x=x1;
   y=y1;
   dx=x2-x1;
   dy=y2-y1;
   p = (2 * dy) - dx;
   glVertex2i(x,y);
   for(int i=0;i<dx;i++)
   {
       if(p<0){
           glVertex2i(++x,y);
           p = p + (2*dy);
       } else {
           glVertex2i(++x,++y);
           p = p + (2*dy) - (2*dx);
       }
   }
   glEnd();
   glFlush();
}

int main(int argc, char** argv)
{
   printf("Enter cord: ");
   scanf("%f%f%f%f", &x1,&y1,&x2,&y2);
   glutInit(&argc, argv);
   glutInitWindowPosition(20,20);
   glutInitWindowSize(200,200);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutCreateWindow("Hi");
   init();
   glutDisplayFunc(DDA);
   glutMainLoop();
   return 0;
}
