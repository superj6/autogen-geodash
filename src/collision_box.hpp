#ifndef COLLISION_BOX_H
#define COLLISION_BOX_H

#include <glad/glad.h>
#include <glm/glm.hpp>

enum CollisionSide{
  SIDE_TOP,
  SIDE_BOTTOM,
  SIDE_LEFT,
  SIDE_RIGHT
};

class CollisionBox{
public:
  glm::vec2 position, size, velocity, acceleration;
  CollisionBox();
  glm::vec2 movePredict(float dt);
  void move(float dt);
  bool checkCollision(CollisionBox &other);
  CollisionSide checkCollisionSide(CollisionBox &other, float dt);
};

#endif
