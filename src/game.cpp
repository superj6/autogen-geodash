#include "game.hpp"
#include "resource_manager.hpp"

Game::Game(unsigned int width, unsigned int height) : width(width), height(height){}

void Game::init(){
  Shader spriteShader = ResourceManager::loadShader("shaders/sprite.vert", "shaders/sprite.frag", "sprite");

  glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
  
  spriteShader.use();
  spriteShader.setMat4("projection", projection);
  spriteShader.setInt("image", 0);

  renderer = new SpriteRenderer(spriteShader);

  ResourceManager::loadTexture("textures/awesomeface.png", "face");
}

void Game::render(){
  renderer->drawSprite(ResourceManager::getTexture("face"), glm::vec2(200.0f, 200.0f), glm::vec2(300.0f, 300.0f), 45.0f);
}


void Game::clear(){
  delete renderer;
}
