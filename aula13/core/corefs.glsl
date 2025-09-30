// Processador de fragmento
#version 330 core
out vec4 FragColor;
in vec3 vColor; // Cor passada pelo shader de vértice

void main() {
    FragColor = vec4(vColor, 1.0);
}
