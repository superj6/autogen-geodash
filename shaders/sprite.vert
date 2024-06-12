#version 330 core
layout (location = 0) in vec2 vertex;

out vec2 texCoords;

uniform mat4 model;
uniform mat4 projection;

void main(){
  texCoords = vertex;
  gl_Position = projection * model * vec4(vertex, 0.0, 1.0);
}
