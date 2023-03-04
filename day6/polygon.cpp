#include<GL/glu.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include<GL/gl.h>
#include<iostream>
void drawPolygon1()
{
    glTranslatef(0.5f,-0.5f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.15,-0.15);
        glVertex2f(0.13,-0.15);
        glVertex2f(0.13,0.15);
        glVertex2f(-0.15,0.15);
    glEnd();
}
void drawPolygon2()
{
    glRotatef(45.0f,1.0f,1.0f,0.0f);
    glBegin(GL_POLYGON);
        glVertex2f(-0.25,-0.15);
        glVertex2f(-0.16,-0.15);
        glVertex2f(-0.16,0.15);
        glVertex2f(-0.25,0.15);
    glEnd();
}
void myDisplay(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0,1.0,0.0);

    drawPolygon1();
    drawPolygon2();

    glFlush();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
    glutInitWindowSize(1280,800);  //width, height
    glutInitWindowPosition(100,150);  // 100 pixels from left edge, //150 pixels from top
    glutCreateWindow("Polygon");

    //register the call back functions
    glutDisplayFunc(myDisplay);


    //myInit();
    glutMainLoop();
    return 0;
}