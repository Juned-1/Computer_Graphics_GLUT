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
float x_position = -10; //positin to need to update everytime
int state = 1;//to decide cube go left or right side, 1 = right, -1 = left
//int round(const float a){return a+0.5;}
int main(int argc,char ** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
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
    gluOrtho2D(-420,420,-420,420);
}
void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
    glPointSize(10.0);//10 pixel
    glTranslatef(0.0,0.0,x_position); //perspective projection changes with z coordinate object do not change its size just change distance from or to observer
    glBegin(GL_QUADS);
    glColor3f(1.0,0.5,0.5);
    glVertex3f(1.0,1.0,0.0);
    glColor3f(0.2,0.1,0.5);
    glVertex3f(-1.0,1.0,0.0);
    glColor3f(0.3,0.3,1.0);
    glVertex3f(-1.0,-1.0,0.0);
    glColor3f(0.5,0.5,0.5);
    glVertex3f(1.0,-1.0,0.0);

    glEnd();
    glutSwapBuffers();//display is not ending it is swaping buffer for animation
}
void reshape(int width,int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //glperspective set the frastun for 3D projection
    gluPerspective(60,1,2.0,50.0); //argument in gluPerspective are seuentially (i)field of view angle -- quite usual angle is 45 or 60 degree
    // ration of width and height of front phase of frustrum and then width height of background phase of frustrum
    //we are using a square it is convenient to give
    //next arguments are z-near(till front phase of frustrum) and z far(till back phase of frustrum)
    //glPerspective(fov,ratio,z-near,z-far);
    //if any object drawn beyond z-far or before z-near will not be printed
    glMatrixMode(GL_MODELVIEW);
}
void timer(int){
    glutPostRedisplay(); //post an urge to redisplay to opengl to call display function agin
    glutTimerFunc(1000/60,timer,0); //we are making call again recursively 60fps
    switch(state){
        case 1:
            if(x_position<-5)
                x_position += 0.15;
            else
                state = -1;
            break;
        case -1:
            if(x_position>=-15)
                x_position-=0.15;
            else
                state = -1;
            break;
    }
}
