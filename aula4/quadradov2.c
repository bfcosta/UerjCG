#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>

void myReshape(int w, int h) {         // window is reshaped
    glViewport (0, 0, w, h);           // update the viewport
    glMatrixMode(GL_PROJECTION);       // update projection
    glLoadIdentity();
    gluOrtho2D(0.0, 1.0, 0.0, 1.0);    // map unit square to viewport
    glMatrixMode(GL_MODELVIEW);
    glutPostRedisplay();               // request redisplay
}

void myDisplay(void) {                 // (re)display callback
    glClearColor(0.5, 0.5, 0.5, 1.0);  // background is gray
    glClear(GL_COLOR_BUFFER_BIT);      // clear the window

    glColor3f(1.0, 0.0, 0.0);          // set color to red
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0);         // step 2: shift rectangle to (0.5, 0.5, 0)
    glRectf(-0.25, -0.25, 0.25, 0.25); // step 1: draw the rectangle at the center
    glPopMatrix();
    
    glColor3f(0.0, 0.0, 1.0);          // set color to blue
    glPushMatrix();
    glTranslatef(0.5, 0.5, 0);         // step 3: shift rectangle to 90.5, 0.5, 0)
    glRotatef(45.0, 0, 0, 1);          // step 2: rotate rectangle 45 degrees on its center
    glRectf(-0.25, -0.25, 0.25, 0.25); // step 1: draw the rectangle at the center
    glPopMatrix();
    glutSwapBuffers();                 // swap buffers
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                        // OpenGL initializations
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);  // double buffering and RGB
    glutInitWindowSize(400, 400);                 // create a 400x400 window
    glutInitWindowPosition(0, 0);                 // ...in the upper left
    glutCreateWindow(argv[0]);                    // create the window
    glutDisplayFunc(myDisplay);                   // setup callbacks
    glutReshapeFunc(myReshape);                   // start it running
    glutMainLoop();                               // ANSI C expects this
    return 0;
}
