#include "game_level.hpp"
#include "resource_manager.hpp"

#include <random>

bool GameLevel::scrolledOffscreen(){
  return scrollOffset <= -blockSize;
}

std::deque<GameObject>& GameLevel::getBlocks(){
  return blocks;
}

void GameLevel::pushColumn(unsigned int columnHeight){
  for(unsigned int i = 0; i < columnHeight; i++){
    GameObject block;
    block.position = glm::vec2(scrollOffset + columnHeights.size() * blockSize, 
        bottomY - (i + 1) * blockSize);
    block.size = glm::vec2(blockSize);
    block.texture = ResourceManager::getTexture("wall");
    block.velocity.x = -scrollVelocity;
    blocks.push_back(block);
  }
  columnHeights.push_back(columnHeight);
}

void GameLevel::popColumn(){
  for(unsigned int i = 0; i < columnHeights.front(); i++){
    blocks.pop_front();
  }
  columnHeights.pop_front();
  scrollOffset += blockSize;
}

void GameLevel::init(unsigned int width, unsigned int height, float blockSize){
  this->blockSize = blockSize;
  scrollVelocity = 250.0f;
  scrollOffset = 0.0f;
  bottomY = height;

  columnHeights.clear();
  blocks.clear();
  while(scrollOffset + columnHeights.size() * blockSize  <= width + blockSize){
    pushColumn(1);
  }
}

void GameLevel::scroll(float dt){  
  scrollOffset -= scrollVelocity * dt;
  for(GameObject &block : blocks){
    block.move(dt);
  }

  if(scrolledOffscreen()){
    popColumn();
    pushColumn(rand() % 3 + 1);
  }
}

void GameLevel::draw(SpriteRenderer &renderer){
  for(GameObject &block : blocks){
    block.draw(renderer);
  }
}
