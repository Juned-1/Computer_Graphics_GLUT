#include<GL/glu.h>
#include <GL/glut.h>  // GLUT, includes glu.h and gl.h
#include<GL/gl.h>
#include<stdlib.h>


/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void Displaying()
{
    //glClearColor(R,G,B, A);
 glClear(GL_COLOR_BUFFER_BIT);//clears the entire window to background color
// glColor4f(1,1,0,1);
glColor3f(1.0,1.0,0.0); //B,G,R

 glBegin(GL_POLYGON);
    glVertex2f(-0.5, -0.5);
    glVertex2f(-0.5, 0.5);
    glVertex2f(0.5, 0.5);
   // glVertex2f(0.5, -0.5);
 glEnd();

 glBegin(GL_LINES);
    glVertex2f(-1, 0.8);
    glVertex2f(1,0.8);
 glEnd();



 glFlush();
}


/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {

   glutInit(&argc, argv);                       // Initialize GLUT
   //glutInitDisplayMode(GLUT_SINGLE |GLUT_RGB);
   glutCreateWindow("Testing1");
   glutInitWindowSize(640, 480);
   glutInitWindowPosition(500, 500);

   glutDisplayFunc(Displaying);


   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}
