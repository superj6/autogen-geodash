#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "game_object.hpp"
#include "sprite_renderer.hpp"

#include <deque>
#include <vector>

class GameLevel{
private:
  float blockSize, scrollOffset, playerVelocity, bottomY, dtSim;
  std::deque<unsigned int> columnHeights;
  std::deque<GameObject> blocks;
  std::vector<glm::vec2> activePositions;
  
  std::pair<glm::vec2, bool> getNextActivePosition(glm::vec2 startPos, std::vector<CollisionBox> column);
  unsigned int getMaxColumnHeight(glm::vec2 startPos);
  unsigned int getRandomColumnHeight();
  void pushColumn(unsigned int columnHeight);
  void popColumn();
public: 
  GameLevel(unsigned int width, unsigned int height, float blockSize, float playerVelocity);
  std::deque<GameObject>& getBlocks();
  void scroll(float playPosX);
  void draw(SpriteRenderer &renderer);
};

#endif
