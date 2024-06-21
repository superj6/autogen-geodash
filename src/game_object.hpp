#ifndef GAME_OBJECT_H
#define GAME_OBJECT_H

#include "texture.hpp"
#include "sprite_renderer.hpp"
#include "collision_box.hpp"

#include <glad/glad.h>
#include <glm/glm.hpp>

class GameObject : public CollisionBox{
public:
  glm::vec3 color;
  float rotation;
  Texture texture;
  GameObject();
  void draw(SpriteRenderer &renderer);
};

#endif
