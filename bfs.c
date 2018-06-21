//bfs
#include<stdio.h>
#include<math.h>
#include<GL/glut.h>

int i,n,x[20],y[20],j,edge1[20],edge2[20],ne,a[20][20],v,q[20],visited[20],f=0,r=-1,pi[20];

void init() {
		  glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
		  glutInitWindowPosition(0,0);
		  glutInitWindowSize(640, 480);
		  glutCreateWindow("bfs");
		  glClearColor(0.0,0.0,0.0,0);
		  glColor3f(1.0,1.0,1.0);
		  glPointSize(15.0);
		  gluOrtho2D(-320,320,-240,240);
}
void delay(int x)
{   int i=0,j=0;
    for(i=0;i<x;i++){for(j=0;j<200000;j++){}}
}
void bfs(int v) {
    for (i=0;i<n;i++)
        if(a[v][i] && !visited[i]){
            q[++r]=i;
            pi[i]=v;
            visited[i]=1;
            glColor3f(1.0,0.0,0.0);
            glBegin(GL_LINES);
            glVertex2i(x[i],y[i]);
            glVertex2i(x[pi[i]],y[pi[i]]);
            glEnd();
            glFlush();
            delay(3000);
        }
    if(f<=r) {
        bfs(q[f++]);
    }
}

void display(void)
{
    for(i=0;i<n;i++){
        glPointSize(15.0);
        glBegin(GL_POINTS);
        glVertex2i(x[i],y[i]);
        glEnd();
        glPointSize(6.0);
        glRasterPos2f(x[i]+10,y[i]+10);
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24,i+48);
        glFlush();
    }
    glColor3f(1.0,1.0,1.0);
    glPointSize(5.0);
    for(i=0;i<n;i++){
        for(j=0;j<n;j++)
        {
            if(a[i][j]){
                glBegin(GL_LINES);
                glVertex2i(x[i],y[i]);
                glVertex2i(x[j],y[j]);
                glEnd();
                glFlush();
            }
        }
    }
    printf("\n Enter the starting vertex:");
    scanf("%d",&v);
    bfs(v);
    for(i=1;i<n;i++){
        if(!visited[i])
            printf("\n Bfs is not possible");
    }

}

int main(int argc,char **argv)
{
    printf("\nNumber of nodes:");
    scanf("%d",&n);
    printf("\nRead node coordinates(x,y):\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&x[i],&y[i]);
        q[i]=0;
        visited[i]=0;
        pi[i]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            a[i][j]=0;
        }
    }
    printf("\nNumber of edges:");
    scanf("%d",&ne);
    printf("\nRead edges(node1,node2):\n");
    for(i=0;i<ne;i++)
    {
        scanf("%d%d",&edge1[i],&edge2[i]);
        a[edge1[i]][edge2[i]]=1;
        a[edge2[i]][edge1[i]]=1;
    }
    printf("\nGraph in matrix form:\n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            printf("%d\t",a[i][j]);
        }
        printf("\n");
    }
    glutInit(&argc, argv);
    init();
    glClear(GL_COLOR_BUFFER_BIT);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}

/*
OUTPUT
 
 Number of nodes:9
 
 Read node coordinates(x,y):
 -200 0
 -100 100
 0 100
 100 100
 200 0
 100 -100
 0 -100
 -100 -100
 0 0
 
 Number of edges:14
 
 Read edges(node1,node2):
 0 1
 0 7
 1 2
 1 7
 2 3
 2 5
 2 8
 3 4
 3 5
 4 5
 5 6
 6 7
 6 8
 7 8
 
 Graph in matrix form:
 0	1	0	0	0	0	0	1	0
 1	0	1	0	0	0	0	1	0
 0	1	0	1	0	1	0	0	1
 0	0	1	0	1	1	0	0	0
 0	0	0	1	0	1	0	0	0
 0	0	1	1	1	0	1	0	0
 0	0	0	0	0	1	0	1	1
 1	1	0	0	0	0	1	0	1
 0	0	1	0	0	0	1	1	0
 
 Enter the starting vertex:0
*/


