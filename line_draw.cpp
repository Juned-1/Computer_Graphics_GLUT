#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void init(void);
void line_display(void);
int main(int argc, char ** argv)
{
    glutInit(&argc,argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowPosition(200,300);
    glutInitWindowSize(500,500);
    
    glutCreateWindow("Line drawing");
    init();
    glutDisplayFunc(line_display);
    glutMainLoop();
}
void init()
{
    glClearColor(1.0,1.0,1.0,0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0.0,200.0,0.0,150.0); //orthogonal projection
}
void line_display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0,0.4,0.2); //set the line color to green with float value, that is what 3f stands for --float
    glBegin(GL_LINES);
        glVertex2i(180,15); //specify line segment geometry.
        glVertex2i(10,145);
    glEnd();
    glFlush();
}