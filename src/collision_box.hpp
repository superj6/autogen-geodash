#ifndef COLLISION_BOX_H
#define COLLISION_BOX_H

#include <glad/glad.h>
#include <glm/glm.hpp>

class CollisionBox{
public:
  glm::vec2 position, size, velocity, acceleration;
  CollisionBox();
  glm::vec2 movePredict(float dt);
  void move(float dt);
};

#endif
