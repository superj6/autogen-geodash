#include "game_level.hpp"
#include "resource_manager.hpp"
#include "collision_box.hpp"

#include <random>

std::pair<glm::vec2, bool> GameLevel::getNextActivePosition(glm::vec2 startPos, std::vector<CollisionBox> column){
  CollisionBox player;
  player.position = startPos;
  player.size = glm::vec2(blockSize);
  player.velocity.y = -400.0f;
  player.velocity.x = playerVelocity;
  player.acceleration.y = 1000.0f; 

  bool collided = false;
  std::pair<glm::vec2, bool> retPos;
  while(!collided && player.position.x <= column[0].position.x + column[0].size.x){
    player.move(dtSim);

    for(CollisionBox &block : column){
      if(player.checkCollision(block)){
	collided = true;
	if(player.checkCollisionSide(block, dtSim) == SIDE_TOP){
	  glm::vec2 pos = glm::vec2(player.position.x, block.position.y - block.size.y);
	  retPos = std::make_pair(pos, true);
	}else{
	  retPos = std::make_pair(glm::vec2(0.0f), false);
	  break;
	}
      }
    }
  }

  if(!collided){
    retPos = std::make_pair(startPos, true);
  }
  
  return retPos;
}

unsigned int GameLevel::getMaxColumnHeight(glm::vec2 startPos){
  CollisionBox player;
  player.position = startPos;
  player.size = glm::vec2(blockSize);
  player.velocity.y = -400.0f;
  player.velocity.x = playerVelocity;
  player.acceleration.y = 1000.0f; 

  std::vector<CollisionBox> column;
  for(unsigned int i = 0; i < bottomY / blockSize - 1; i++){
    CollisionBox block;
    block.position = glm::vec2(scrollOffset + columnHeights.size() * blockSize,
	bottomY - (i + 1) * blockSize);
    block.size = glm::vec2(blockSize);
    column.push_back(block);
  }

  unsigned int maxHeight = 0, maxHit = column.size();
  while(player.position.x <= column[0].position.x + column[0].size.x){
    player.move(dtSim);

    for(unsigned int i = 0; i < column.size(); i++){
      CollisionBox &block = column[i];
      if(i < maxHit && player.checkCollision(block)){
	maxHit = i;
	if(player.checkCollisionSide(block, dtSim) == SIDE_TOP){
	  maxHeight = std::max(maxHeight, i + 1);
	}
      }
    }
  }

  maxHeight = std::max(maxHeight, maxHit);
  
  return maxHeight;
}

unsigned int GameLevel::getRandomColumnHeight(){
  unsigned int maxHeight = 0;
  for(glm::vec2 pos : activePositions){
    unsigned int height = getMaxColumnHeight(pos);
    maxHeight = std::max(maxHeight, height);
  }

  int height = rand() % maxHeight + 1;
  while(height == columnHeights.end()[-2] && columnHeights.back() < height){
    height = rand() % maxHeight + 1;
  }
  return height;
}

void GameLevel::pushColumn(unsigned int columnHeight){
  std::vector<CollisionBox> column;
  for(unsigned int i = 0; i < columnHeight; i++){
    GameObject block;
    block.position = glm::vec2(scrollOffset + columnHeights.size() * blockSize, 
        bottomY - (i + 1) * blockSize);
    block.size = glm::vec2(blockSize);
    column.push_back(block);
    
    block.texture = ResourceManager::getTexture("wall"); 
    blocks.push_back(block);
  }
  columnHeights.push_back(columnHeight);
   
  bool landNewCol = false;
  glm::vec2 firstNewColPos = glm::vec2(0.0f);
  std::vector<glm::vec2> nextActivePositions; 
  for(glm::vec2 pos : activePositions){ 
    CollisionBox player;
    player.position = pos;
    player.acceleration.y = 1000.0f;
    player.size = glm::vec2(blockSize);

    player.move(dtSim);
    if(player.checkCollision(column.back())){
      if(player.checkCollisionSide(column.back(), dtSim) == SIDE_TOP){
	if(!landNewCol || pos.x < firstNewColPos.x){
	  firstNewColPos = pos;
	  landNewCol = true;
	} 
      }
    }

    std::pair nextPosPair = getNextActivePosition(pos, column);
    if(nextPosPair.second){
      glm::vec2 nextPos = nextPosPair.first;
      if(nextPos != pos){
        if(!landNewCol || nextPos.x < firstNewColPos.x){
	  firstNewColPos = nextPos;
	  landNewCol = true;
	} 
      }else{
        nextActivePositions.push_back(nextPos);
      }
    }
  }

  if(landNewCol){
    glm::vec2 pos = firstNewColPos;
    while(pos.x < scrollOffset + columnHeights.size() * blockSize){
      nextActivePositions.push_back(pos);
      pos.x += dtSim * playerVelocity;
    }
  }

  std::swap(activePositions, nextActivePositions);
}

void GameLevel::popColumn(){
  for(unsigned int i = 0; i < columnHeights.front(); i++){
    blocks.pop_front();
  }
  columnHeights.pop_front();
  scrollOffset += blockSize;
}

std::deque<GameObject>& GameLevel::getBlocks(){
  return blocks;
}

GameLevel::GameLevel(unsigned int width, unsigned int height, float blockSize, float playerVelocity){
  this->blockSize = blockSize;
  this->playerVelocity = 250.0f;
  scrollOffset = 0.0f;
  bottomY = height;
  dtSim = 1.0f / 30.0f;

  activePositions.push_back(glm::vec2(0.0f, bottomY - 2 * blockSize));

  columnHeights.clear();
  blocks.clear();
  while(scrollOffset + columnHeights.size() * blockSize  <= width + blockSize){
    pushColumn(1);
  }
}

void GameLevel::scroll(float playerPosX){  
  if(playerPosX - scrollOffset >= 4 * blockSize){
    popColumn();

    unsigned int height = getRandomColumnHeight();
    pushColumn(height);  
  }
}

void GameLevel::draw(SpriteRenderer &renderer){
  for(GameObject &block : blocks){
    block.draw(renderer);
  }
}
