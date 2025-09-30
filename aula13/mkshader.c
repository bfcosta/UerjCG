#include <stdlib.h>
#include <stdio.h>
#ifdef USE_GLAD
#include <glad/glad.h>
#else
#include <GL/glew.h>
#endif
#include "defs.h"

void buildProgram(const char * vsfile, const char * fsfile) {
    int IsLinked, maxLength;
    char *shaderProgramInfoLog;

    loadVertexShader(vsfile);
    loadFragmentShader(fsfile);
    shaderprogram = glCreateProgram();
    /* Attach our shaders to our program */
    glAttachShader(shaderprogram, vertexshader);
    glAttachShader(shaderprogram, fragmentshader);
    /* This is needed if location is not set in shader code */
    //~ glBindAttribLocation(shaderprogram, 0, "aPos");
    //~ glBindAttribLocation(shaderprogram, 1, "aColor");
    glLinkProgram(shaderprogram); // Link our program 
    glGetProgramiv(shaderprogram, GL_LINK_STATUS, (int *)&IsLinked);
    if(!IsLinked) {
       glGetProgramiv(shaderprogram, GL_INFO_LOG_LENGTH, &maxLength);
       shaderProgramInfoLog = (char *)malloc(maxLength);
       glGetProgramInfoLog(shaderprogram, maxLength, &maxLength, shaderProgramInfoLog);
       printf("Program link error: %s\n",shaderProgramInfoLog);
       free(shaderProgramInfoLog);
       exit(0);
    }
    glUseProgram(shaderprogram); // Load shader into the pipeline
}
