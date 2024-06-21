#include "game_object.hpp"

GameObject::GameObject() : CollisionBox(), color(1.0f), rotation(0.0f), texture(){}

void GameObject::draw(SpriteRenderer &renderer){
  renderer.drawSprite(texture, position, size, rotation, color);
}
