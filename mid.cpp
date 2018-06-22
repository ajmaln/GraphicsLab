#include<stdio.h>
#include<GL/glut.h>

float x,y,z,p,r;

void init(){
   glClearColor(0.0,0.0,0.0,0.0);
   glColor3f(1.0,0.0,0.0);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void mpc()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(3.0);
   glBegin(GL_POINTS);
   glVertex2i(0,r);
   x=0;
   y=r;
   p=1-r;
   while(x<=y){
       if(p<0){
           ++x;
           glVertex2i(x,y);
           glVertex2i(-x,-y);
           glVertex2i(-x,y);
           glVertex2i(x,-y);
           glVertex2i(y,x);
           glVertex2i(-y,-x);
           glVertex2i(-y,x);
           glVertex2i(y,-x);
           p+=(2*x)+3;
       } else {
           ++x; 
           --y;
           glVertex2i(x,y);
           glVertex2i(-x,-y);
           glVertex2i(-x,y);
           glVertex2i(x,-y);
           glVertex2i(y,x);
           glVertex2i(-y,-x);
           glVertex2i(-y,x);
           glVertex2i(y,-x);
           //p=p+((2*x)+3) - ((2*y)+1);
           p+=2*(x-y+1);
       }
   }
   glEnd();
   glFlush();
}

int main(int argc, char** argv)
{
   printf("Enter r: ");
   scanf("%f", &r);
   glutInit(&argc, argv);
   glutInitWindowPosition(200,200);
   glutInitWindowSize(500,500);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutCreateWindow("Hi");
   init();
   glutDisplayFunc(mpc);
   glutMainLoop();
   return 0;
}
