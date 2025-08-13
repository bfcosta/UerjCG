#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/glut.h>
#include <stdio.h>

GLenum errorCheck (void) {
    GLenum code;
    const GLubyte *string;

    code = glGetError ();
    if (code != GL_NO_ERROR) {
        string = gluErrorString (code);
        fprintf( stderr, "OpenGL error: %s\n", string );
    }
    return code;
}

void init (void) {
    // Set display-window color to white.
    glClearColor (1.0, 1.0, 1.0, 0.0);
    // Set projection parameters.
    glMatrixMode (GL_PROJECTION);
    gluOrtho2D (0.0, 200.0, 0.0, 150.0);
    //errorCheck ( );
}

void lineSegment (void) {
    // Clear display window.
    glClear (GL_COLOR_BUFFER_BIT);
    // Set line segment color to green.
    glColor3f (0.0, 0.4, 0.2);
    // Specify line-segment geometry.
    glBegin (GL_LINES);
        glVertex2i (180, 15);
        glVertex2i (10, 145);
    glEnd ( );
    // Process all OpenGL routines as quickly as possible.
    glFlush ( );
    //errorCheck ( );
}

void main (int argc, char** argv) {
    // Initialize GLUT.
    glutInit (&argc, argv);
    // Set display mode.
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    // Set top-left display-window position.
    glutInitWindowPosition (50, 100);
    // Set display-window width and height.
    glutInitWindowSize (400, 300);
    // Create display window.
    glutCreateWindow ("An Example OpenGL Program"); 
    // Execute initialization procedure.
    init ( );
    // Send graphics to display window.
    glutDisplayFunc (lineSegment);
    // Display everything and wait.
    glutMainLoop ( );
}
