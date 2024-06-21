#include "collision_box.hpp"

CollisionBox::CollisionBox() : position(0.0f), size(1.0f), velocity(0.0f), acceleration(0.0f){}

glm::vec2 CollisionBox::movePredict(float dt){
  return position + velocity * dt + 0.5f * acceleration * dt * dt;
}

void CollisionBox::move(float dt){
  position = movePredict(dt);
  velocity += acceleration * dt;
}

bool CollisionBox::checkCollision(CollisionBox &other){
  CollisionBox *objs[2] = {this, &other};
  for(int dim = 0; dim < 2; dim++){
    for(int i = 0; i < 2; i++){
      if(objs[i]->position[dim] + objs[i]->size[dim] < objs[!i]->position[dim]){
        return false;
      }
    }
  }
  return true;
}

CollisionSide CollisionBox::checkCollisionSide(CollisionBox &other, float dt){
  if(movePredict(-dt).y + size.y <= other.movePredict(-dt).y + 1){
    return TOP;
  }
  return LEFT;
}
