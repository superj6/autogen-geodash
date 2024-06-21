#include "collision_box.hpp"

CollisionBox::CollisionBox() : position(0.0f), size(1.0f), velocity(0.0f), acceleration(0.0f){}

glm::vec2 CollisionBox::movePredict(float dt){
  return position + velocity * dt + 0.5f * acceleration * dt * dt;
}

void CollisionBox::move(float dt){
  position = movePredict(dt);
  velocity += acceleration * dt;
}
