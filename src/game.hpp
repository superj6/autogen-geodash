#ifndef GAME_H
#define GAME_H

#include "sprite_renderer.hpp"

class Game{
private:
  unsigned int width, height;
  SpriteRenderer *renderer;
public:
  Game(unsigned int width, unsigned int height);
  void init();
  void render();
  void clear();
};

#endif
