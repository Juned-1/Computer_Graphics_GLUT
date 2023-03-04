#include<iostream>
#include<GL/glu.h>
#include<GL/gl.h>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
void myInit(void);
void lineBres(int,int,int,int);
void display(void);
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_SINGLE);
    glutInitWindowSize(1365,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Bresenhem Line");
    myInit();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
void myInit()
{
    glClearColor(1.0,1.0,1.0,1);
    glColor3f(0.3,0.8,0.8);
    glPointSize(2.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-780,780,-420,420);
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_POINTS);
    lineBres(-200,200,200,200);
    lineBres(-200,-200,200,-200);
    lineBres(-200,-200,-200,200);
    lineBres(200,-200,200,200);
    glEnd();
    glFlush();
}
void lineBres(int x0,int y0,int xend,int yend)
{
    int dx = fabs(xend - x0), dy = fabs(yend - y0);
    int x, y;
    x = x0, y = y0;
    //glVertex2i(x,y);

    if(dx > dy){ //slope m<1
        glVertex2i(x,y);
        int p = 2*dy - dx;
        for(int i = 0; i < fabs(dx); i++){
            x++;
            if(p<0)
                p+=2*dy;
            else{
                y++;
                p+=2*(dy - dx);

            }
            glVertex2i(x,y);
        }
    }
    else{ //slope m>=1
        glVertex2i(x,y);
        int p = 2*dx - dy;
        for(int i = 0; i < fabs(dy); i++){
            y++;
            if(p<0)
                p+=2*dx;
            else{
                x++;
                p+=2*(dx - dy);
            }
            glVertex2i(x,y);
        }
    }
}