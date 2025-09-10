#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include <math.h>
#include <stdio.h>

GLdouble tx, ty, rz, rad, vert[9];

void drawTriangle(void) {
	glColor3f(1.0f, 1.0f, 1.0f);
	glPushMatrix();
	glTranslated(tx, ty, 0.0);
	glRotated(rz, 0, 0, 1);
	glBegin(GL_TRIANGLES);
	  glVertex3dv(&vert[0]);
	  glVertex3dv(&vert[3]);
	  glVertex3dv(&vert[6]);
	glEnd(); 
	glPopMatrix();
}

void myDisplay(void) {                 
    glClearColor(0.0, 0.0, 0.0, 1.0);  
    glClear(GL_COLOR_BUFFER_BIT);      
    drawTriangle();
    glutSwapBuffers();                 
}

void myReshape(int w, int h) {
    glViewport (0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();
}

void myKeyHandler(unsigned char key, int x, int y) {
    // x, y sem uso na função
    switch (key) {
         case 'c':
         case 'C':
         case ' ':
             tx = 0.0;
             ty = 0.0;
             rz = 0.0;
         break;
         
         //~ case 'd':
         case 'D':
         case GLUT_KEY_LEFT:
             tx = tx - 0.02;
         break;
         
         //~ case 'f':
         case 'F':
         case GLUT_KEY_RIGHT:
             tx = tx + 0.02;
         break;
         
         //~ case 'e':
         case 'E':
         case GLUT_KEY_UP:
             ty = ty + 0.02;
         break;
         
         //~ case 'g':
         case 'G':
         case GLUT_KEY_DOWN:
             ty = ty - 0.02;
         break;
         
         case 'r':
         case 'R':
             rz = rz + 5.0;
         break;

         case 27: // Escape ascii code
             exit(0);

         default:
             printf("Tecla '%c' sem função associada.\n", key);
    }
    glutPostRedisplay();
}

void init(void) {
    tx = 0.0;
    ty = 0.0;
    rz = 0.0;
    rad = 0.2;
    vert[0] = -0.866*rad; vert[1] = -0.5*rad; vert[2] = 0.0; 
    vert[3] = 0.866*rad; vert[4] = -0.5*rad; vert[5] = 0.0; 
    vert[6] = 0.0; vert[7] = rad; vert[8] = 0.0; 
    printf("Teclas ativas:\n\n");
    printf("\t'c' ou espaço para centralizar\n");
    printf("\t'd' para ir à esquerda\n");
    printf("\t'f' para ir à direita\n");
    printf("\t'e' para subir\n");
    printf("\t'g' para descer\n");
    printf("\t'r' para girar\n");
    printf("\tESC para terminar\n");
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(0, 0);
    glutCreateWindow(argv[0]);
    glutDisplayFunc(myDisplay);
    glutReshapeFunc(myReshape);
    glutKeyboardFunc(myKeyHandler);
    init();
    glutMainLoop();
    return 0;
}
