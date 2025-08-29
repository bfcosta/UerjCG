#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

GLUquadric *disco;
GLint slice, rings, fps;
GLdouble radius, shift;

void myReshape(int w, int h) {
    glViewport (0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
	gluOrtho2D(0, 1.0, 0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void drawDisc(void) {
	glColor3f(1.0f, 1.0f, 1.0f); 
	glPushMatrix();
	glTranslated(shift, 0.5, 0.0);
	gluDisk(disco, 0, radius, slice, rings);
	glPopMatrix();
}

void myDisplay(void) {                 
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glClear(GL_COLOR_BUFFER_BIT);      
    drawDisc();
    glutSwapBuffers();                 
}

void shiftDisc(int value) {
	shift = shift + 0.005;
	if (shift - radius > 1.0) {
		shift = -1.2 * radius;
	}
	glutPostRedisplay();
	glutTimerFunc(1000/fps, shiftDisc, 1);
}

void init(void) {
	disco = gluNewQuadric();
	slice = 24;
	rings = 1;
	fps = 25;
	radius = 0.2;
	shift = 0.5;
	glutTimerFunc(1000/fps, shiftDisc, 1);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                        
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  
    glutInitWindowSize(400, 400);                 
    glutInitWindowPosition(0, 0);                 
    glutCreateWindow(argv[0]);                    
    glutDisplayFunc(myDisplay);                   
    glutReshapeFunc(myReshape);                   
    init();
    glutMainLoop();
    gluDeleteQuadric(disco);                              
    return 0;
}
