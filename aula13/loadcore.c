#include <GL/glew.h>
#include "defs.h"
#include <stdio.h>

void loadData(void) {
    GLfloat vertices[18] = { 
      /* posição */         /* cor */
      -0.8f, -0.8f, 0.0f,   1.0f, 0.0f, 0.0f,
      0.8f, -0.8f, 0.0f,    0.0f, 1.0f, 0.0f,
      0.0f, 0.8f, 0.0f,     0.0f, 0.0f, 1.0f };
    glGenVertexArrays(1, &vao); // cria array
    glBindVertexArray(vao);
    glGenBuffers(1, &vbo);      // cria buffer
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    // carrega vertices no buffer
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    // especifica os dados do primeiro atributo: posição
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*)0);
    glEnableVertexAttribArray(0); // habilita posição em location 0
    // especifica os dados do segundo atributo: cor
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (void*) (3*sizeof(GLfloat)));
    glEnableVertexAttribArray(1); // habilita cor em location 1
}
