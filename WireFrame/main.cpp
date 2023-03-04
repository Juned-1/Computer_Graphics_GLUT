#include<stdio.h>
#include<GL/gl.h>
#include<Gl/glu.h>
#include<GL/glut.h>
#include<math.h>
#define PI 3.1416
void setPixel(GLint, GLint);
void ellipse(GLint, GLint, GLint, GLint, GLfloat);
void display();
void resize(int, int);
int main(int argc, char**argv)
{
    glutInit(&argc,argv); //initialize GLUT
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); //initialize display
    glutInitWindowSize(400,400); //set display-window width &amp; height
    glutInitWindowPosition(50,50); //set display-window upper-left
    glutCreateWindow("Wire Frame Model of Globe"); //create display-
    glutDisplayFunc(display); //call graphics to be displayed on the
    glutReshapeFunc(resize); //calls whenever frame buffer window is
    glutMainLoop(); //display everything and wait
    return 0;
}
void resize(int w, int h)
{
    //set projection paramaters
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,w,0.0,h);
    glViewport(0.0, 0.0, w, h);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,1.0,0.0);
    glPointSize(2.0);
    GLint xc=200; // setting the center of globe
    GLint yc=200;
    GLint ry=100; // setting the radius_accross_y-axis of ellipse
    //change angle (0 – 360) and radius_accross_x-axis (0 to 100 in steps of 10)
    // and draw ellipses
    for(GLint theta =1;theta<=360;theta++)
        for(GLint rx=100;rx>=0;rx-=10)
            ellipse(xc, yc, rx, ry, theta);
    GLint rx=100; //setting the radius_accross_x-axis of ellipse as constant
    //change angle (0 – 360) and radius_accross_y-axis (0 to 100 in steps of 10)
    // and draw ellipses
    for(GLint theta =1;theta<=360;theta++)
        for(GLint ry=100;ry>=0;ry-=10)
            ellipse(xc, yc, rx, ry, theta);
    glFlush();
}
void ellipse(GLint xc, GLint yc, GLint rx, GLint ry, GLfloat theta)
{
    GLint x = xc + rx * cos(theta* PI/180.0);
    GLint y = yc + ry * sin(theta* PI/180.0);
    setPixel(x,y);
}
void setPixel(GLint xCoordinate, GLint yCoordinate)
{
    glBegin(GL_POINTS);
    glVertex2i(xCoordinate,yCoordinate);
    glEnd();
}
