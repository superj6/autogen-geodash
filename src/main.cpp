#include "game.hpp"
#include "resource_manager.hpp"

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include <iostream>

const unsigned int SCREEN_WIDTH = 800;
const unsigned int SCREEN_HEIGHT = 600;

Game game(SCREEN_WIDTH, SCREEN_HEIGHT);

void framebufferSizeCallback(GLFWwindow* window, int width, int height){
  glViewport(0, 0, width, height);
}  

void keyCallback(GLFWwindow *window, int key, int scancode, int action, int mode){
  if(key == GLFW_KEY_ESCAPE && action == GLFW_PRESS){
    glfwSetWindowShouldClose(window, true);
  }
  if(key >= 0 && key < 1024){
    if(action == GLFW_PRESS){
      game.setKey(key, true);
    }else if(action == GLFW_RELEASE){
      game.setKey(key, false);
    }
  }
}

int main(){
  glfwInit();
  glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
  glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
  glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
#ifdef __APPLE__
  glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
#endif
  glfwWindowHint(GLFW_RESIZABLE, false);

  GLFWwindow* window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Wow Window!", NULL, NULL);
  if (window == NULL)
  {
    std::cout << "Failed to create GLFW window" << std::endl;
    glfwTerminate();
    return -1;
  }

  glfwMakeContextCurrent(window);

  if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
  {
    std::cout << "Failed to initialize GLAD" << std::endl;
    return -1;
  }

  glfwSetKeyCallback(window, keyCallback);
  glfwSetFramebufferSizeCallback(window, framebufferSizeCallback);  

  glViewport(0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  game.init();

  float deltaTime = 0.0f, lastFrame = 0.0f;

  //render loop
  while(!glfwWindowShouldClose(window)){
    float currentFrame = glfwGetTime();
    deltaTime = currentFrame - lastFrame;
    lastFrame = currentFrame;
    glfwPollEvents();

    game.processInput();

    game.update(deltaTime);

    glClearColor(0.3f, 0.1f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    game.render();

    glfwSwapBuffers(window);
  }

  ResourceManager::clear();
  game.clear();

  glfwTerminate();

  return 0;
}
