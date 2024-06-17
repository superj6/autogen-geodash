#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture.hpp"
#include "sprite_renderer.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>

class GameObject{
public:
  glm::vec2 position, size, velocity, acceleration;
  glm::vec3 color;
  float rotation;
  Texture texture;
  GameObject();
  static glm::vec2 movePredict(glm::vec2 position, glm::vec2 velocity, glm::vec2 acceleration, float dt);
  glm::vec2 movePredict(float dt);
  void move(float dt);
  void draw(SpriteRenderer &renderer);
};

#endif
