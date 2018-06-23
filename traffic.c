#include<GL/glut.h>
#include<unistd.h>
#include<stdio.h>
#define RED 0
#define GREEN 1

int window;
int signalColor = RED;

void initGL(float width, float height)
{
    glClearColor(1.0f,1.0f,1.0f,1.0f);
    glMatrixMode(GL_PROJECTION);
    gluPerspective(45.0f, (GLdouble)width/(GLdouble)height, 0.0f, 10.0f);
    glMatrixMode(GL_MODELVIEW);
}

int sigX=0, sigY=0, sigZ=0;

float step = 0.0, time = 0.0;

void DrawSignalCar()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glTranslatef(0.0, 0.0,-6.0);
    glColor3f(0.0f,0.0f,0.0f);
    glRectf(0.0f,0.0f,0.5f,1.7f);

    if(signalColor == GREEN){
        glTranslatef(sigX+0.25, sigY+1.25, sigZ);
        glColor3f(0.0,1.0,0.0);
        glutSolidSphere(0.2, 30, 30);
    } else {
        glColor3f(1.0,0.0,0.0);
        glTranslatef(sigX+0.25, sigY+0.5, sigZ);
        glutSolidSphere(0.2, 30, 30);
        glTranslatef(0.0, 0.75, 0);
    }    
    
    glColor3f(1.0, 0.0, 0.0);
    glTranslatef(step,0.0, 0.0);
    glRectf(-2.0, -2.0, -0.5, -1.5);
    if(time>=2.0 && time<=3.1){
        step += 0.05;
        signalColor = GREEN;
    } 
    
    if (time>3.1) {
        signalColor = RED;
        step=-3.2;
    }

    if(step<0.0){
        step+=0.05;
    }

    if(time>=4.0) {
        time=0;
    }

    time += 0.01;
    printf("%f %f\n", time, step);
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_ALPHA|GLUT_DEPTH);
    glutInitWindowSize(640,480);
    window = glutCreateWindow("Traffic");
    glutDisplayFunc(&DrawSignalCar);
    glutIdleFunc(&DrawSignalCar);
    initGL(640,480);
    glutMainLoop();
    return 1;
}
