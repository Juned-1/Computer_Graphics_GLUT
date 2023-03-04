#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void lineDDA(int,int,int,int);
void myInit(void);
void display(void);
//int round(const float a){return a+0.5;}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Chess Board");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
void myInit()
{
    glClearColor(1.0,1.0,1.0,1);
    glColor3f(0.0,0.0,0.0);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780,780,-780,780);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    for(int i = 0; i < 9; i++){
        lineDDA(-315,315,600-i*100,600-i*100); //calling dda algo
    }
    for(int i = 0; i < 9 ; i++){
        lineDDA(-315+i*79,-315+i*79,600,-200);
    }
    glEnd();
    glFlush();
}
void lineDDA(int x0, int xend, int y0, int yend)
{
    int dx = xend - x0, dy = yend - y0, steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;
    if(fabs(dx) > fabs(dy))
        steps = fabs(dx);
    else
        steps = fabs(dy);
    xIncrement = (float)dx/(float)steps;
    yIncrement = (float)dy/(float)steps;
    glVertex2i(round(x),round(y));
    for(k = 0; k < steps; k++){
        x+=xIncrement;
        y+=yIncrement;
        glVertex2i(round(x),round(y));
    }
}