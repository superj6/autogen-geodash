#include "sprite_renderer.hpp"

void SpriteRenderer::initRenderData(){
  float vertices[] = {
    0.0f, 0.0f,
    1.0f, 0.0f,
    0.0f, 1.0f,
    1.0f, 1.0f
  };
  unsigned int indices[] = {
    0, 1, 2,
    1, 2, 3
  };
 
  glGenVertexArrays(1, &vaoId);
  glGenBuffers(1, &vboId);
  glGenBuffers(1, &eboId);

  glBindVertexArray(vaoId);

  glBindBuffer(GL_ARRAY_BUFFER, vboId);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, eboId);
  glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 2 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);
  glBindVertexArray(0);
}

SpriteRenderer::SpriteRenderer(Shader shader) : shader(shader){
  initRenderData();
}

SpriteRenderer::~SpriteRenderer(){
  glDeleteVertexArrays(1, &vaoId);
  glDeleteBuffers(1, &vboId);
  glDeleteBuffers(1, &eboId);
}

void SpriteRenderer::drawSprite(Texture texture, glm::vec2 position, glm::vec2 size, float rotation, glm::vec3 color){
  glm::mat4 model = glm::mat4(1.0f);
  
  //apply ops in reverse
  model = glm::translate(model, glm::vec3(position, 0.0f));

  model = glm::translate(model, glm::vec3(0.5f * size, 0.0f));
  model = glm::rotate(model, glm::radians(rotation), glm::vec3(0.0f, 0.0f, 1.0f));
  model = glm::translate(model, glm::vec3(-0.5f * size, 0.0f));

  model = glm::scale(model, glm::vec3(size, 1.0f));

  shader.use();
  shader.setMat4("model", model);
  shader.setVec3("spriteColor", color);

  glActiveTexture(GL_TEXTURE0);
  texture.bind();

  glBindVertexArray(vaoId);
  glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
  glBindVertexArray(0);
}
