#include <stdlib.h>
#include <stdio.h>
#ifdef USE_GLAD
#include <glad/glad.h>
#else
#include <GL/glew.h>
#endif
#include "defs.h"

void loadFragmentShader (const char * fsfile) {
    int IsCompiled_FS, maxLength;
    char *fragmentInfoLog;
    
    fragmentshader = glCreateShader(GL_FRAGMENT_SHADER);
    fragmentsource = readTextFile(fsfile);
    /* Send the fragment shader source code to GL */
    if (fragmentsource != NULL)
        glShaderSource(fragmentshader, 1, (const GLchar**)&fragmentsource, 0);
    else {
        printf("Could not open file: %s\n",fsfile);
        exit(0);
    }
    glCompileShader(fragmentshader); // Compile the fragment shader
    glGetShaderiv(fragmentshader, GL_COMPILE_STATUS, &IsCompiled_FS);
    if(!IsCompiled_FS) {
       glGetShaderiv(fragmentshader, GL_INFO_LOG_LENGTH, &maxLength);
       fragmentInfoLog = (char *)malloc(maxLength);
       glGetShaderInfoLog(fragmentshader, maxLength, &maxLength, fragmentInfoLog);
       printf("Fragment shader compilation error: %s\n",fragmentInfoLog);
       free(fragmentInfoLog);
       return;
    }
}
