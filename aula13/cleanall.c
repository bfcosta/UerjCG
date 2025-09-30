#include <stdlib.h>
#ifdef USE_GLAD
#include <glad/glad.h>
#else
#include <GL/glew.h>
#endif
#include "defs.h"

void cleanup(void) {
    glUseProgram(0);
    glDetachShader(shaderprogram, vertexshader);
    glDetachShader(shaderprogram, fragmentshader);
    glDeleteProgram(shaderprogram);
    glDeleteShader(vertexshader);
    glDeleteShader(fragmentshader);
    free(vertexsource);
    free(fragmentsource);
}
