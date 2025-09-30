#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include <GL/glut.h>
#include "defs.h"
#include <stdio.h>

void drawShader(void) {
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    // build mvp matrix
    glm::mat4 mvMat = glm::mat4(1.0f);  // identity matrix
    glm::mat4 vwMat = glm::lookAt(glm::vec3(0.0f, 0.0f, 1.0f), 
         glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));
    glm::mat4 prMat = glm::ortho(-1.2f, 1.2f, -1.2f, 1.2f, -1.2f, 1.2f);
    glm::mat4 mvp = prMat * vwMat * mvMat;
    // get mvp location
    int mvpLocation = glGetUniformLocation(shaderprogram, "mvp");
    // update shader uniform
    glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, glm::value_ptr(mvp));

    glBindVertexArray(vao); // only needed if bind is not active
    glDrawArrays(GL_TRIANGLES, 0, 3); // draw triangle
    glutSwapBuffers();
}
