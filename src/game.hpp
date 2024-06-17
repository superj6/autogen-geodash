#ifndef GAME_H
#define GAME_H

#include "sprite_renderer.hpp"
#include "game_object.hpp"
#include "game_level.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_OVER
};

class Game{
private:
  unsigned int width, height;
  float blockSize;
  bool stillPressed;
  bool keys[1024];
  SpriteRenderer *renderer;
  GameState state;
  GameObject player;
  GameLevel *level;
  bool playerOnGround;
  bool checkCollision(GameObject &obj1, GameObject &obj2);
public:
  Game(unsigned int width, unsigned int height);
  void init();
  void setKey(unsigned int key, bool isPressed);
  void processInput();
  void update(float dt);
  void render();
  void clear();
};

#endif
