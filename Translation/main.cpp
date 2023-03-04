#include<iostream>
#include<vector>
#include<windows.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<GL/glut.h>
using namespace std;
vector<float>x;
vector<float>y;
float tx = 0, ty = 0;
float sx, sy;
int nverts;
void init()
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
    glBegin(GL_POLYGON);
    for(int i = 0; i < ::nverts; i++){
        glVertex2f(::x[i],::y[i]);
    }
    glTranslatef(tx,ty,0);
    glScalef(sx,sy,0);
    glEnd();
    glutSwapBuffers();
}
int main(int argc,char ** argv)
{
    cout<<"Enter number of vertices:"<<endl;
    cin>>::nverts;
    cout<<"Enter Coordinates :"<<endl;
    for(int i = 0; i < ::nverts; i++){
        float xc,yc;
        cin>>xc>>yc;
        ::x.push_back(xc);
        ::y.push_back(yc);
    }

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1365,800);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Plygon");
    init();
    glutDisplayFunc(display);
    cout<<"1.Translation\n2.Scaling\n3.Reflaction\n4.Do nothing"<<endl;
    cout<<"Enter your choice:"<<endl;
    int ch;
    cin>>ch;
    switch(ch){
    case 1:
        cout<<"Enter translation factor:"<<endl;
        cin>>::tx>>::ty;
        break;
    case 2:
        cout<<"Enter scaling factor:"<<endl;
        cin>>::sx>>::sy;
    case 3:
        break;
    case 4:
        break;
    default:
        break;
    }

    glutMainLoop();
    return 0;
}
