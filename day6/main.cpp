#include<GL/glu.h>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdlib.h>
#include<stdio.h>
#include<iostream>
using namespace std;

void myDisplay(){
	//making square or polygon
	glColor3f(0.0,1.0, 1.0);
	glBegin(GL_POLYGON);
		glVertex3f(25,25,0);
		glVertex3f(75,25,0);
		glVertex3f(75, 75, 0);
		glVertex3f(25,75, 0);
	glEnd();
	glFlush();

}
//for translation
void Translate(int x, int y, int z){
	glTranslatef(x,y,z);
}
//for rotation
void Rotate(int angle, int x, int y, int z){
 	glRotatef(angle,x,y,z);
 }
 //for scaling
 void Scale(int x, int y, int z){
 	glScalef(x,y,z);
 }

	//main function
int main(int argc, char **argv){

//general code for glut display
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transformation");
	glClear(GL_COLOR_BUFFER_BIT);
	glClearColor(1.0, 1.0, 1.0, 1.0);
	glMatrixMode(GL_PROJECTION);
	gluOrtho2D(0, 500, 0, 500);

	myDisplay();

	printf("1:Translation 2:Rotation 3:Scaling 0:TO BREAK\n");
	printf("Input Tranformation sequuence = ");
	int i,Transform[100];
	for(i = 0; i<100; i++){
		int a; scanf("%d", &a);
		if(a == 0) break;
		Transform[i] = a;
	}

	int n = i;

	glPushMatrix();
	//switch cases for various transformations
	for(int i = 0; i<n; i++){
		switch(Transform[i]){

			case 1:
				int  i;
				cout << "Enter translationn scale = \n";
				cin >> i;
				Translate(i,i,0);
				break;
			case 2:
				int a;
				cout << "Enter angle = \n";
				Rotate(a,0,0,1);
				break;
			case 3:
				int s;
				cout << "Enter scaling factor = \n";
				Scale(s,s,s);
				break;
			default:
				printf("Incorrect input");
				break;
		}
	}

	myDisplay();
	glPopMatrix();
	glutMainLoop();


	return 0;
}
