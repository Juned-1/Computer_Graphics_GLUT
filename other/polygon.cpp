/*If we see give polygon points in clockwise order it  consider it from back side, but in 2d plane we can 
look to backside of polygon
To get polygon from front size we give vertices in anticlockwise direction.
For example for the following triangle, the vertices are from top-left-right(anticlockwise),
not from top-right-left(clockwise)
Condition 2: Polygon should be convex, and Polygon vertices must lie on the same plane*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void lineDDA(int,int,int,int);
void myInit(void);
void display(void);
void reshape(int,int);
//int round(const float a){return a+0.5;}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(1366,768);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Polygon");
    myInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutMainLoop();
    return 0;
}
void myInit()
{
    glClearColor(0,0,0,1);
    //glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780,780,-420,420);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    //glLoadIdentity();
    glPointSize(10.0);//10 pixel
    glBegin(GL_POLYGON);
    glVertex2f(0.0,5.0);
    glVertex2f(-4.0,-3.0);
    glVertex2f(4.0,-3.0);
    glVertex2f(5.0,-2.0);
    glEnd();
    glFlush();
}
void reshape(int width,int height){
    /*reshaping clicpping area(viewport) with resize of
     window - otheriwse it leads to distortion of object we draw*/
     glViewport(0,0,width,height);//point x,y relative to bottom of window and height, width of x, y
     /*x and y will be 0 and widht and height is width of the window and height of the window*/
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity(); //reset the parameters of projection matrix
    gluOrtho2D(-10,10,-10,10);//ortho projection from center left,rigth,bottom,top
    glMatrixMode(GL_MODELVIEW); //in model view we can draw stuff
}