#include<GL/glu.h> //this comes with openGL and compiler --glu -opengl utility library
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h, glut by default do not comes with compiler
//It need to be installed gl and glu are included in glut library so we may remove these two file from inclusion
//But some version of opengl that might not be included in glut, so better to keep inclusion
//glut is also utility toolkit provide windowing api, it deals with os to make opengl independent of os
#include<GL/gl.h> //header file for openGL API --gl is opengl header file
#include<iostream>
void display(void);
void init(void);
int main(int argc,char ** argv)
{
    //initialize glut library
    glutInit(&argc,argv); //argc number of command line string and argv array of strings -- string contain command line argument
    
    //Initialize display mode
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE); //take unsigend int argument -- constants defined in glut api
    //To initialize multiple value we can use or bitwise or(|)
    //display mode will be rgb and double mode

    /*Craete a window --glut helps to create window from os and put open gl stuff in it, dince opengl do not provide window*/
    
    glutInitWindowPosition(200, 100);//initialize glut window position
    glutInitWindowSize(500,500); //width and height

    glutCreateWindow("Window 1"); //argument glutCreateWindow accept is title of window
    //setting background color of screen
    init();

    //display callback to dawn or redraw display -- display call back need to be called after we create window
    //display callback is function which is called when window is need to be drawn or redrawn
    glutDisplayFunc(display); //it takes one argument which is function pointer--pointer to a function which returns void and takes no argument

    //Program loop runs continuously to mentain window infinitely until it is pressed to exit
    glutMainLoop();
}

void init()
{
    glClearColor(1.0,1.0,1.0,1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void display()
{
    //clear canvas or area before drawing -- because we might have some drawing left from previous stage
    //we draw actual thing on frame buffer
    //clear pixels of frame buffer to a default color
    glClear(GL_COLOR_BUFFER_BIT); //glClear is used to clear frame buffer/ depth buffer so we need to specify what we want to clear -for frame buffer it is GL_COLOR_BUFFER

    //glLoadIdentity() reset all the transformation of the current matrix that we are currently in
    //glLoadIdentity();


    //draw

    glFlush(); //glFlush() is used to draw in display whaever is in frame buffer--after drawing is finished then display

}