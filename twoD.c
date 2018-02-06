#include<GL/glut.h>
#include<stdio.h>
#include<math.h>


int v, x[10], y[10], xt[10], yt[10], ch, tx, ty, sx, sy, r, i;

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(-100.0,100.0,-100.0,100.0);
}

void setPixel()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0);
    glBegin(GL_LINE_LOOP);
    for(i=0;i<v;i++) {
        glVertex2i(x[i], y[i]);
    }
    glEnd();
    glBegin(GL_LINE_LOOP);
    for(i=0;i<v;i++) {
        glVertex2i(xt[i], yt[i]);     
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv)
{
    printf("Enter the number of vertices: ");
    scanf("%d", &v);
    printf("Enter the points to be ploted: ");
    for(i=0;i<v;i++) {
        scanf("%d%d", &x[i], &y[i]);
    }
    printf("\nMenu\n1.Translation\n2.Scaling\n3.Rotation");
    printf("\nEnter the choice: ");
    scanf("%d", &ch);
    switch(ch)
    {
        case 1:
            printf("\n Perform translation");
            printf("\nEnter translation values");
            scanf("%d%d", &sx, &sy);
            for(i=0;i,v;i++) {
                xt[i] = x[i]*sx;
                yt[i] = y[i]*sy;
            }
            break;
        case 2:
            printf("\nPerform scaling");
            printf("\nEnter scaling values: ");
            scanf("%d%d", &sx, &sy);
            for(i=0; i<v; i++) {
                xt[i] = x[i]*sx;
                yt[i] = y[i]*sy;
            }
            break;
        case 3:
            printf("\nPerform rotation");
            printf("\nEnter rotating angle: ");
            scanf("%d", &r);
            for(i=0; i<v; i++) {
                xt[i] = (x[i]*cos(r))-(y[i]*sin(r));
                yt[i] = (x[i]*sin(r))-(x[i]*cos(r));
            }
            break;
        default:
            printf("\nInvalid Choice!");
            break;      
    }
    
    glutInit(&argc,argv);
    glutInitWindowPosition(20,20);
    glutInitWindowSize(200,200);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutCreateWindow("2-D");
    init();
    glutDisplayFunc(setPixel);
    glutMainLoop();
    return 0;
}
    
    
    
    
    
