/*Animation is just clear and redraw in the successive frame,
If frame rate is high then displaying the frame at faster rate, and distance we move is 
sufficiently low, then it will give us smooth frame
For our example we will use 60fps, screen will be refreshed 60 time in a second -- most display use this farme
rate -- so tha we have no distortion or any other problem*/
/*If we see give polygon points in clockwise order it  consider it from back side, but in 2d plane we can 
look to backside of polygon
To get polygon from front size we give vertices in anticlockwise direction.
For example for the following triangle, the vertices are from top-left-right(anticlockwise),
not from top-right-left(clockwise)
Condition 2: Polygon should be convex, and Polygon vertices must lie on the same plane

Problem: The Problem for drawing complex geomatric shape(like a cube) is when we redraw before rendering complete
shape it might project and go for longer period of time, which give undesirable distorted animation.
Solution: To solve this problem in low performance computer we use double buffering GLUT_DOUBLE
There are two frame buffer, one is front buffer and other is back buffer,
front buffer hold the geomatry that currently on the display
back buffer which is used to draw, it is not in the display, it is used as memory
When we finish drawing we can swap the buffer(throuh pointer swap),front buffer will become back buffer and
back buffer will become front buffer -- Now in the next frame buffer all the stuff need to drawn is carried out
in the back buffer and then swap the buffer again and so on
So animation in double buffer is redraw and swap buffer

Animation by double buffer might be slow but eliminate the problem of distortion caused by
single buffer animation*/
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
void lineDDA(int,int,int,int);
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
    //glLoadIdentity();
    glPointSize(10.0);//10 pixel
    glBegin(GL_POLYGON);
    glVertex2f(x_position,1.0);
    glVertex2f(x_position,-1.0);
    glVertex2f(x_position+2.0,-1.0);
    glVertex2f(x_position+2.0,1.0);

    glEnd();
    glutSwapBuffers();//display is not ending it is swaping buffer for animation
}
void reshape(int width,int height){
    glViewport(0,0,width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-10,10,-10,10);
    glMatrixMode(GL_MODELVIEW);
}
void timer(int){
    glutPostRedisplay(); //post an urge to redisplay to opengl to call display function agin
    glutTimerFunc(1000/60,timer,0); //we are making call again recursively 60fps
    switch(state){
        case 1:
            if(x_position<8)
                x_position += 0.15;
            else
                state = -1;
            break;
        case -1:
            if(x_position>=-10)
                x_position-=0.15;
            else
                state = -1;
            break;
    }
}