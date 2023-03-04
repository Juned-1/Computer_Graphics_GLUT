#include<GL/glu.h>
#include <GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
void display(void);
void init(void);
void reshape(int,int);
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutInitWindowPosition(200, 100);
    glutInitWindowSize(500,500);
    glutCreateWindow("Window 1");
    init();
    glutDisplayFunc(display);

    glutReshapeFunc(reshape); //window will be reshaped after window reshaped
    glutMainLoop();
}
void init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0,200.0,0.0,150.0);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(10.0); //size of point is 10 pixel
    glBegin(GL_POINT);//begin drawing vertices, GL_POINT tell opengl it is going to draw point
        //glVertexn, take n argument for n plane
        glVertex2f(5,5); //takes 2 argument for 2D plane, it can be 3 for 3D, it can be i, f, d etc. i for int, f for float and d for double  types of arguments
        glVertex2f(-5,-5);
    glEnd(); //finished drawing vertices --opengl can use it to make the primitives
    glFlush();
}

void reshape(int w,int h)
{
    //viewport are rectangular area inside which we can draw primitives
    glViewport(0,0,(GLsizei)w,(GLsizei)h);//glViewport takes four arguments x,y width and height x,y are related bottom left corner of window, can be considered as origin. width and height of viewport

    glMatrixMode(GL_PROJECTION); //change matrix, generally it is ModelView Matrix, so we need to switch on projection matrix

    glLoadIdentity(); //reset reccurent matrix

    //certesian two dimensional plane is known as orthographic projection
    
    gluOrtho2D(-10,10,-10,10); //takes four argument left, right bottom and topmost coordinate

    glMatrixMode(GL_MODELVIEW); //switch back to model view

}