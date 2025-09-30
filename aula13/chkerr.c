#include "defs.h"
#include <stdlib.h>
#include <stdio.h>

GLenum errorCheck (void) {
    GLenum code;
    const GLubyte *string;

    code = glGetError();
    while (code != GL_NO_ERROR) {
        string = gluErrorString(code);
        fprintf( stderr, "OpenGL error: %s\n", string );
        code = glGetError();
    }
    return code;
}
