#ifndef DEFS_H
#define DEFS_H

#include <GL/gl.h>
#include <GL/glu.h>

extern GLuint vao, vbo;
extern GLuint vertexshader, fragmentshader, shaderprogram;
extern GLchar *fragmentsource, *vertexsource;

GLchar *readTextFile(const char *name);
void loadVertexShader (const char * vsfile);
void loadFragmentShader (const char * fsfile);
void cleanup(void);
void buildProgram(const char * vsfile, const char * fsfile);
void loadData(void);
GLenum errorCheck (void);
void drawShader(void);

#endif
