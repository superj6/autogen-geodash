#include "game.hpp"
#include "resource_manager.hpp"

void Game::moveCameraToPlayer(){
  Shader spriteShader = ResourceManager::getShader("sprite");

  glm::vec3 cameraPos = glm::vec3(player.position.x - 3 * blockSize, 0.0f, 0.0f);
  glm::mat4 view = glm::lookAt(cameraPos, cameraPos+glm::vec3(0.0f, 0.0f, -1.0f), glm::vec3(0.0f, 1.0f, 0.0f));
  spriteShader.setMat4("view", view);
  
}

Game::Game(unsigned int width, unsigned int height) : width(width), height(height), blockSize(50.0f), state(GAME_MENU), player(){}

void Game::init(){
  Shader spriteShader = ResourceManager::loadShader("shaders/sprite.vert", "shaders/sprite.frag", "sprite");

  glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);

  spriteShader.use();
  spriteShader.setMat4("projection", projection);
  spriteShader.setInt("image", 0);

  renderer = new SpriteRenderer(spriteShader);

  ResourceManager::loadTexture("textures/awesomeface.png", "face");
  ResourceManager::loadTexture("textures/wall.jpg", "wall");

  player.size = glm::vec2(blockSize);
  player.texture = ResourceManager::getTexture("wall");
  player.position.x = 3 * blockSize;
  player.position.y = 50.0f;
  player.acceleration.y = 1000.0f;
  player.color = glm::vec3(1.0f, 2.0f, 1.0f);
  playerOnGround = false;

  moveCameraToPlayer();

  level = new GameLevel();

  stillPressed = true;
}

void Game::setKey(unsigned int key, bool isPressed){
  keys[key] = isPressed;
}

void Game::processInput(){
  if(state == GAME_MENU){
    if(keys[GLFW_KEY_SPACE] && !stillPressed){
      state = GAME_ACTIVE;
      level->init(width, height, blockSize);
      player.velocity.x = 250.0f;
    }
  }else if(state == GAME_ACTIVE){
    if(keys[GLFW_KEY_SPACE]){
      if(playerOnGround){
	player.velocity.y = -400.0f;
      }
    }
  }else if(state == GAME_OVER){
    if(keys[GLFW_KEY_SPACE] && !stillPressed){
      state = GAME_MENU;

      player.position.x = 3 * blockSize;
      player.position.y = 50.0f;
      player.acceleration.y = 1000.0f;
      player.velocity.y = 0.0f;
      player.color = glm::vec3(1.0f, 2.0f, 1.0f);
      playerOnGround = false;

      moveCameraToPlayer();

      delete level;
      level = new GameLevel();
    }
  }
  if(keys[GLFW_KEY_SPACE]){
    stillPressed = true;
  }else{
    stillPressed = false;
  }
}

void Game::update(float dt){
  if(state != GAME_ACTIVE){
    return;
  }

  player.move(dt);
  level->scroll(player.position.x);

  moveCameraToPlayer();
  
  playerOnGround = false;
  float newPosY = 0.0f;
  for(GameObject &block : level->getBlocks()){
    if(player.checkCollision(block)){
      if(player.checkCollisionSide(block, dt) == SIDE_TOP){
        newPosY = block.position.y - player.size.y;
	playerOnGround = true;
      }else{
        state = GAME_OVER;
	playerOnGround = false;
	break;
      }
    } 
  }

  if(playerOnGround){
    player.position.y = newPosY;
    player.velocity.y = 0;
  }
}

void Game::render(){
  player.draw(*renderer);
  level->draw(*renderer);
}


void Game::clear(){
  delete renderer;
  delete level;
}
