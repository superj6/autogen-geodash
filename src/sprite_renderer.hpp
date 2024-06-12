#ifndef SPRITE_RENDERER_H
#define SPRITE_RENDERER_H

#include "shader.hpp"
#include "texture.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class SpriteRenderer{
private:
  Shader shader;
  unsigned int vaoId, vboId, eboId;
  void initRenderData();
public:
  SpriteRenderer(Shader shader);
  ~SpriteRenderer();
  void drawSprite(Texture texture, glm::vec2 position, glm::vec2 size, float rotation = 0.0f, glm::vec3 color = glm::vec3(1.0f));
};

#endif
