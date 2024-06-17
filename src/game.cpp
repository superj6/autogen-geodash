#include "game.hpp"
#include "resource_manager.hpp"

bool Game::checkCollision(GameObject &obj1, GameObject &obj2){
  GameObject *objs[2] = {&obj1, &obj2};
  for(int dim = 0; dim < 2; dim++){
    for(int i = 0; i < 2; i++){
      if(objs[i]->position[dim] + objs[i]->size[dim] < objs[!i]->position[dim]){
        return false;
      }
    }
  }
  return true;
}

Game::Game(unsigned int width, unsigned int height) : width(width), height(height), blockSize(50.0f), state(GAME_MENU), player(){}

void Game::init(){
  Shader spriteShader = ResourceManager::loadShader("shaders/sprite.vert", "shaders/sprite.frag", "sprite");

  glm::mat4 projection = glm::ortho(0.0f, (float)width, (float)height, 0.0f, -1.0f, 1.0f);
  projection  = projection * glm::lookAt(glm::vec3(0.0f, 0.0f, 0.25f), glm::vec3(0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

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
  playerOnGround = false;

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
      playerOnGround = false;

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
  level->scroll(dt);

  glm::vec2 playerPrevPos = player.movePredict(-dt);

  playerOnGround = false;
  for(GameObject &block : level->getBlocks()){
    if(checkCollision(player, block)){
      if(playerPrevPos.y + player.size.y <= block.position.y + 1){
        player.position.y = block.position.y - player.size.y;
	player.velocity.y = 0;
	playerOnGround = true;
      }else{
        state = GAME_OVER;
      }
    } 
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
