#include<iostream>
#include <GL/gl.h>
#include<GL/glu.h>
#include <GL/glut.h>
#include<math.h>
void lineDDA(int x0, int y0, int xend,int yend){
    int dx = xend - x0;
    int dy = yend - y0;
    int steps, k;
    float xIncrement, yIncrement, x = x0, y = y0;
    if(fabs(dx) > fabs(dy)) {
        steps = fabs(dx);
    } else {
        steps = fabs(dy);
    }
    xIncrement = (float)dx/(float)steps;
    yIncrement = (float)dy/(float)steps;
    glVertex2i(round(x),round(y));
    for(k = 0; k < steps; k++) {
        x+=xIncrement;
        y+=yIncrement;
        glVertex2i(round(x), round(y));
    }
}

void display(void){

    glClear(GL_PROJECTION);

    glBegin(GL_POINTS);

    lineDDA(-350, 200, 350, 200); //x-line
    lineDDA(-350, -200, 350, -200); //
    lineDDA(-350, 200, -350, -200);
    lineDDA(350, 200, 350, -200);    
    glEnd();
    glFlush();
}

void myInit(void) {
    glClearColor(1.0, 0.0, 0.0, 0.0);
    glColor3f(100.0, 76.0, 7.66);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780, 780, -420, 430);
}

int main (int argc, char** argv)

{

    glutInit(&argc, argv);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutInitWindowSize(1366, 768);

    glutInitWindowPosition(0, 0);

    glutCreateWindow("Line Drawing");

    myInit();

    glutDisplayFunc(display);

    glutMainLoop();

}
