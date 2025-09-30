#include <stdlib.h>
#include <stdio.h>
#include <glad/glad.h>
#include <GL/glut.h>
#include "defs.h"

GLuint vertexshader, fragmentshader, shaderprogram;
GLchar *fragmentsource, *vertexsource;

void init(void) {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.2f, 1.2f, -1.2f, 1.2f, -1.2f, 1.2f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0.0f, 0.0f, 1.0f,
              0.0f, 0.0f, 0.0f, 
              0.0f, 1.0f, 0.0f );
}

void draw(void) {
    GLfloat vertices[18] = { 
      /* posição */         /* cor */
      -0.8f, -0.8f, 0.0f,   1.0f, 0.0f, 0.0f,
      0.8f, -0.8f, 0.0f,    0.0f, 1.0f, 0.0f,
      0.0f, 0.8f, 0.0f,     0.0f, 0.0f, 1.0f };

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);  // draw triangle
      for (int i=0; i<3; i++) {
        glColor3fv(&vertices[6*i + 3]);
        glVertex3fv(&vertices[6*i]);
      }
    glEnd();
    glutSwapBuffers();
}

/* Our program's entry point */
int main(int argc, char *argv[]) {
    glutInit (&argc, argv);
    // Set display mode.
    glutInitDisplayMode (GLUT_DOUBLE | GLUT_RGB);
    // Set top-left display-window position.
    glutInitWindowPosition (50, 50);
    // Set display-window width and height.
    glutInitWindowSize (300, 300);
    // Create display window.
    glutCreateWindow ("An OpenGL Shader Example with GLAD (Compatibility Mode)"); 
    // inicialização da biblioteca GLAD
    if (!gladLoadGL()) {
        printf("Could not load GLAD.\n");
        exit(0);
    }
    buildProgram("compat/compatvs.glsl", "compat/compatfs.glsl" );
    init();
    // Send graphics to display window.
    glutDisplayFunc(draw);
    // Display everything and wait.
    glutMainLoop();
    cleanup();
    return 0;
}
