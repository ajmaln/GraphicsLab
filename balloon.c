/*MOVNG BALLOON
  S8 CSE*/
   
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<unistd.h>
#define ESCAPE 27
float rti=0.0f;
int window;

void InitGL(int Width,int Height)
{
  glClearColor(0.0f,0.0f,0.0f,0.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
  glEnable(GL_DEPTH_TEST);
  glShadeModel(GL_SMOOTH);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluPerspective(45.0f,(GLfloat)Width/(GLfloat)Height,0.1f,100.0f);
  glMatrixMode(GL_MODELVIEW);
}

void DrawGLScene()
{
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
  glLoadIdentity();
  glTranslatef(0.0f,rti,-6.0f);
  glColor3f(0.0f,1.0f,1.0f);
  glutSolidSphere(0.5,30,30);
  glColor3f(0.0f,0.0f,1.0f);
  glRectf(0.0,-2.0,0.01,0.0);
  rti+=0.005f;
  if(rti>2)
      rti=-2.0f;    
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
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_ALPHA|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    glutInitWindowPosition(0,0);
    window=glutCreateWindow("Moving car");
    glutDisplayFunc(&DrawGLScene);
    glutFullScreen();
    glutIdleFunc(&DrawGLScene);
    glutKeyboardFunc(&keyPressed);
    InitGL(640,480);
    glutMainLoop();
    return 1;
 }        
