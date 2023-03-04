#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
//void lineDDA(int,int,int,int);
void myInit(void);
void display(void);
void reshape(int,int);
void timer(int);
float angle = 0.0; //positin to need to update everytime
int state = 1;//to decide cube go left or right side, 1 = right, -1 = left
//int round(const float a){return a+0.5;}
/*To view 3d we need technique fpr hidden surface removal which is also called depth testing*/
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Polygon");
    myInit();
    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutTimerFunc(0,timer,0); /*callback to register a function to call after some amount of time,arg-time in ms,
    func. 0 is argument that timer function accepts*/
    glutMainLoop();
    return 0;
}
void myInit()
{
    glClearColor(0,0,0,1);
    //glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(60,1,2.0,50.0);
    glEnable(GL_DEPTH_TEST); //to enable depth testing -- glenable is used to enable some functionality of gl
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //depth buffer stores data about depth testing depth buffer will be cleared with each farme
    glLoadIdentity();
    glPointSize(10.0);//10 pixel
    glTranslatef(0.0,0.0,-8.0);
    glRotatef(angle,1.0,0.0,0.0);
    glRotatef(angle,0.0,1.0,0.0);
    glRotatef(angle,0.0,0.0,1.0);
    glBegin(GL_QUADS);
     // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f); //vertices for front phase are defined anticlock wise and vetices of back phase are defined with clockwise coordinate
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);

      // Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);

      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);

      // Back face (z = -1.0f)
      glColor3f(1.0f, 1.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);

      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);

      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 1.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);

    glEnd();
    glutSwapBuffers();
}
void reshape(int width,int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    gluPerspective(60,1,2.0,50.0);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/60,timer,0);
    angle += 0.8*4;
    if(angle>360.0)
        angle -= 360.0;
}
