/* LINE CLIPPING
   S8 CSE*/
   
#include<GL/glut.h>
#include<stdio.h>

float x[10],y[10];
int i,j=0,m;

void init(void)
{
   glClearColor(0.0,0.0,0.0,0.0);
   glColor3f(0.0,1.0,1.0);
   glMatrixMode(GL_PROJECTION);
   gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void setPixel()
{
   glClear(GL_COLOR_BUFFER_BIT);
   glPointSize(10.0);
   glBegin(GL_LINES);
   glVertex2i(10,10);
   glVertex2i(50,10);
   glEnd();
   glBegin(GL_LINES);
   glVertex2i(10,50);
   glVertex2i(50,50);
   glEnd();
   glBegin(GL_LINES);
   glVertex2i(50,50);
   glVertex2i(50,10);
   glEnd();
   glBegin(GL_LINES);
   glVertex2i(10,50);
   glVertex2i(10,10);
   glBegin(GL_LINES);
   glVertex2i(x[0],y[0]);
   glVertex2i(x[1],y[1]);
   glEnd();
   glFlush();
}

int main(int argc,char **argv)
{
   printf("Enter the line end points");
   for(i=0;i<2;i++)
   {
      scanf("%f%f",&x[i],&y[i]);
   }
   m=(y[1]-y[0])/(x[1]-x[0]);
   for(i=0;i<2;i++)
   {
      while(x[i]<10||x[i]>50||y[i]<10||y[i]>50)
      {
          if(x[i]<10)
          {
             y[i]+=m*(10-x[i]);
             x[i]=10;
          }
          else if(x[i]>50)
          {
             y[i]+=m*50-x[i];
             x[i]=50;
          }
          else if(y[i]>50)
          {
             x[i]+=(10-x[i])/m;
             y[i]=50;
          }
          else if(y[i]<10)
          {
             x[i]+=(10-x[i])/m;
             y[i]=10;
          }
      }
      x[j]=x[i];
      y[j]=y[i];
      j++;
   }
   glutInit(&argc,argv);
   glutInitWindowPosition(20,20);
   glutInitWindowSize(200,200);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutCreateWindow("LINE");
   init();
   glutDisplayFunc(setPixel);
   glutMainLoop();
   return 0; 
 }                 
          
            
                   
   
