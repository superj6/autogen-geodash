#include "resource_manager.hpp"

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

#include <iostream>
#include <sstream>
#include <fstream>

std::map<std::string, Shader> ResourceManager::shaders;
std::map<std::string, Texture> ResourceManager::textures;

std::string ResourceManager::loadStringFromFile(const char *file){
  std::ifstream fileStream(file);
  std::stringstream strStream;
  strStream << fileStream.rdbuf();
  fileStream.close();
  return strStream.str();
}

Shader ResourceManager::loadShaderFromFile(const char *vertShaderFile, const char *fragShaderFile){
  std::string vertCode, fragCode;
  try{
    vertCode = loadStringFromFile(vertShaderFile);
    fragCode = loadStringFromFile(fragShaderFile);
  }catch(std::exception e){
    std::cout << "ERROR: shader failed to load file" << std::endl;
  }

  const char *vertShaderCode = vertCode.c_str();
  const char *fragShaderCode = fragCode.c_str();

  Shader shader;
  shader.compile(vertShaderCode, fragShaderCode);

  return shader;
}

Texture ResourceManager::loadTextureFromFile(const char *file){
  Texture texture;
  
  int width, height, nrChannels;
  unsigned char *data = stbi_load(file, &width, &height, &nrChannels, 0);
  if(data){
    texture.generate(width, height, nrChannels, data);
    stbi_image_free(data);
  }else{
    std::cout << "ERROR: texture failed to load file" << std::endl;
  }
  
  return texture;
}

Shader ResourceManager::loadShader(const char *vertShaderFile, const char *fragShaderFile, std::string name){
  shaders[name] = loadShaderFromFile(vertShaderFile, fragShaderFile);
  return shaders[name];
}

Shader ResourceManager::getShader(std::string name){
  return shaders[name];
}

Texture ResourceManager::loadTexture(const char *file, std::string name){
  textures[name] = loadTextureFromFile(file);
  return textures[name];
}

Texture ResourceManager::getTexture(std::string name){
  return textures[name];
}

void ResourceManager::clear(){
  for(auto it : shaders){
    it.second.clear();
  }
  for(auto it : textures){
    it.second.clear();
  }
}
