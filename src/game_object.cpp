#include "game.hpp"

GameObject::GameObject() : position(0.0f), size(1.0f), velocity(0.0f), acceleration(0.0f), color(1.0f), rotation(0.0f), texture(){}

glm::vec2 GameObject::movePredict(glm::vec2 position, glm::vec2 velocity, glm::vec2 acceleration, float dt){
  return position + velocity * dt + 0.5f * acceleration * dt * dt;
}

glm::vec2 GameObject::movePredict(float dt){
  return movePredict(position, velocity, acceleration, dt);
}

void GameObject::move(float dt){
  position = movePredict(dt);
  velocity += acceleration * dt;
}

void GameObject::draw(SpriteRenderer &renderer){
  renderer.drawSprite(texture, position, size, rotation, color);
}
