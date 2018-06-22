/*MOVING CAR
  S8 CSE*/
  
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<unistd.h>
#define ESCAPE 27
int window;
float rti=-5.0f;

void InitGL(int Width,int Height)
{ glClearColor(1.0f,1.0f,1.0f,1.0f);//glClearDepth(1.0);//glDepthFunc(GL_LESS);//glEnable(GL_DEPTH_TEST);
  glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,10.0f);
  glMatrixMode(GL_MODELVIEW);
}

float ballX=0.0f;
float ballY=0.0f;
float ballZ=0.0f;

void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(rti,0.0f,-6.0f);
  glBegin(GL_POLYGON);
  glColor3f(1.0f,0.0f,0.0f);
  glVertex3f(-1.0f,1.0f,0.0f); 
  glVertex3f(0.5f,1.0f,0.0f);
  glVertex3f(1.0f,0.5f,0.0f);
  //glColor3f(0.0f,1.0f,0.0f);
  glVertex3f(1.5f,0.5f,0.0f);
  glVertex3f(1.5f,0.0f,0.0f);
  //glVertex3f(1.0f,0.0f,0.0f);
  //glColor3f(0.0f,0.0f,1.0f);
  glVertex3f(-1.5f,0.0f,0.0f);
  glEnd();
  glColor3f(0.0,0.0,0.0);
  glTranslatef(ballX-0.5,ballY,ballZ);
  glutSolidSphere(0.3,20,20);
  glTranslatef(ballX+1.0,ballY,ballZ);
  glutSolidSphere(0.3,20,20);
  rti+=0.05f;
  if(rti>6)
      rti=-5.0f;    
  glutSwapBuffers();
}

void keyPressed(unsigned char key,int x,int y)
{
   if(key==ESCAPE)
   {
      glutDestroyWindow(window);
      exit(0);
    }
 }
 
 int main(int argc,char **argv)
 {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE);
    glutInitWindowSize(640,480);                                                                        //glutInitWindowPosition(0,0);
    window=glutCreateWindow("Moving car");                                                              //glutDisplayFunc(&DrawGLScene);//glutFullScreen();
    glutIdleFunc(&DrawGLScene);
    glutKeyboardFunc(&keyPressed);
    InitGL(640,480);
    glutMainLoop();
    return 1;
 }        
