#include <stdlib.h>
#include <stdio.h>
#include <GL/glew.h>
#include <GL/glut.h>
#include "defs.h"

GLuint vao, vbo;
GLuint vertexshader, fragmentshader, shaderprogram;
GLchar *fragmentsource, *vertexsource;

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
    glutCreateWindow ("An OpenGL Shader Example with GLEW (core mode)"); 
    // inicialização da biblioteca GLEW
    glewExperimental = GL_TRUE;
    GLenum gcode = glewInit();
    if (gcode != GLEW_OK) {
        printf("Error: %s\n",glewGetErrorString(gcode));
        exit(0);
    };
    buildProgram("core/corevs.glsl", "core/corefs.glsl" );
    loadData();
    // Send graphics to display window.
    glutDisplayFunc(drawShader);
    // Display everything and wait.
    glutMainLoop();
    cleanup();
    return 0;
}
