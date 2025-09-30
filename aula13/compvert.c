#include <stdlib.h>
#include <stdio.h>
#ifdef USE_GLAD
#include <glad/glad.h>
#else
#include <GL/glew.h>
#endif
#include "defs.h"

void loadVertexShader (const char * vsfile) {
   int IsCompiled_VS, maxLength;
   char *vertexInfoLog;

   vertexshader = glCreateShader(GL_VERTEX_SHADER);
   vertexsource = readTextFile(vsfile);
   /* Send the vertex shader source code to GL */
   if (vertexsource!= NULL)
        glShaderSource(vertexshader, 1, (const GLchar**)&vertexsource, 0);
   else {
        printf("Could not open file: %s\n",vsfile);
        exit(0);
   }
   glCompileShader(vertexshader); // Compile the vertex shader
   glGetShaderiv(vertexshader, GL_COMPILE_STATUS, &IsCompiled_VS);
   if(!IsCompiled_VS) {
       glGetShaderiv(vertexshader, GL_INFO_LOG_LENGTH, &maxLength);
       vertexInfoLog = (char *)malloc(maxLength);
       glGetShaderInfoLog(vertexshader, maxLength, &maxLength, vertexInfoLog);
       printf("Vertex shader compilation error: %s\n",vertexInfoLog);
       free(vertexInfoLog);
       return;
   }
}
