#include<GL/glu.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include<GL/gl.h>
#include<stdio.h>


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(640,480);  //width, height
    glutInitWindowPosition(100,150);  // 100 pixels from left edge, 150 pixels from top
    glutCreateWindow("My first program");


    //myInit();
    glutMainLoop();
}