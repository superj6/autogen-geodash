#ifndef GAME_LEVEL_H
#define GAME_LEVEL_H

#include "game_object.hpp"
#include "sprite_renderer.hpp"

#include <deque>

class GameLevel{
private:
  float blockSize, scrollOffset, scrollVelocity, bottomY;
  std::deque<unsigned int> columnHeights;
  std::deque<GameObject> blocks;
  bool scrolledOffscreen();
  void pushColumn(unsigned int columnHeight);
  void popColumn();
public: 
  GameLevel(){}
  std::deque<GameObject>& getBlocks();
  void init(unsigned int width, unsigned int height, float blockSize);
  void scroll(float dt);
  void draw(SpriteRenderer &renderer);
};

#endif
