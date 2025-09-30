// Processador de vértice
#version 330 core
layout (location = 0) in vec3 aPos; // Posição do vértice
layout (location = 1) in vec3 aColor; // Cor do vértice
out vec3 vColor; // cor passada ao fragmento
uniform mat4 mvp; // matriz com as transformações necessárias

void main() {
    gl_Position = mvp * vec4(aPos, 1.0);
    vColor = aColor;
}
