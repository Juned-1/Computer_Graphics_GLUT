#include<iostream>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
#define pi 3.142857
using namespace std;
void myInit(void);
void display(void);
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB  | GLUT_SINGLE);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(200,200);
    glutCreateWindow("Draw Circle");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
}
void myInit()
{
    glClearColor(0.0,0.0,0.0,1);
    glColor3f(1.0,0.0,0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780,780,-420,420);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    float x,y,i;
    for(i=0; i<(2*pi); i+=0.001)
    {
        x = 300*cos(i);
        y = 300*sin(i);
        glVertex2i(x,y);
    }
    glEnd();
    glFlush();

}