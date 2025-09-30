// Versão inicial sendo explicitamente definida
// Livro texto não especifica a versão utilizada
#version 110 
// Processador de Vértice
void main () {
   // opção 1 de transformação de coordenadas
   gl_Position = gl_ProjectionMatrix * (gl_ModelViewMatrix * gl_Vertex); 
   //~ gl_Position = gl_ModelViewProjectionMatrix * gl_Vertex; // opção 2
   //~ gl_Position = ftransform(); // opção 3 
   gl_FrontColor = gl_Color;
}
