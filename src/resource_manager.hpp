#ifndef RESOURCE_MANAGER_H
#define RESOURCE_MANAGER_H

#include "shader.hpp"
#include "texture.hpp"

#include <map>
#include <string>

class ResourceManager{
private:
  static std::map<std::string, Shader> shaders; 
  static std::map<std::string, Texture> textures; 
  
  ResourceManager(){}
  static std::string loadStringFromFile(const char *file);
  static Shader loadShaderFromFile(const char *vertShaderFile, const char *fragShaderFile);
  static Texture loadTextureFromFile(const char *file);

public:
  static Shader loadShader(const char *vertShaderFile, const char*fragShaderFile, std::string name);
  static Shader getShader(std::string name);
  static Texture loadTexture(const char *file, std::string name);
  static Texture getTexture(std::string name);
  static void clear();
};

#endif
