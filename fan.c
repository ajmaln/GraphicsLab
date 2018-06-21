/*ROTATING FAN
  s8 CSE*/
  
#include<GL/glut.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<unistd.h>
#define ESCAPE 27
static GLfloat spin=0.0;
int window;

void InitGL(int Width,int Height)
{
  glClearColor(1.0f,1.0f,1.0f,1.0f);
  glClearDepth(1.0);
  glDepthFunc(GL_LESS);
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
  glPushMatrix();
  glRotatef(spin,0.0,0.0,1.0);
  glColor3f(0.0f,0.0f,0.0f);
  glTranslatef(0.0f,0.0f,-6.0f);
  glutSolidSphere(0.15,30,30);
  glRectf(0.2,-2.0,-0.2,-0.4);
  glRectf(-0.2,2.0,0.2,0.4);
  glRectf(0.4,-0.2,1.7,0.22);
  glRectf(-0.4,0.2,-1.7,-0.22);
  glPopMatrix();
  glutSwapBuffers();
}

void spinDisplay(void)
{
   spin=spin+10.0;
   if(spin>360.0)
     spin=spin-360.0;
   glutPostRedisplay();
}

void reshape(int w,int h)
{
  glViewport(0,0,(GLsizei) w,(GLsizei) h);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(-50.0,50.0,-50.0,50.0,-1.0,1.5);
  glMatrixMode(GL_MODELVIEW);
  glLoadIdentity();
}

void mouse(int button,int state,int x,int y)
{
   switch(button)
   {
      case GLUT_LEFT_BUTTON:if(state==GLUT_DOWN)
                               glutIdleFunc(spinDisplay);
                            break;
      case GLUT_MIDDLE_BUTTON:if(state==GLUT_DOWN)
                               glutIdleFunc(NULL);
                            break;
      default:
        break;
   }
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
    window=glutCreateWindow("Spinning Fan");
    glutDisplayFunc(&DrawGLScene);
    glutFullScreen();
    glutIdleFunc(&DrawGLScene);
    glutKeyboardFunc(&keyPressed);
    glutMouseFunc(mouse);
    InitGL(640,480);
    glutMainLoop();
    return 1;
 }        
                                  
