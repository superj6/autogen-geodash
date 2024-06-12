#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include <string>

class Shader{
private:
  unsigned int id;
  void checkShaderCompileErrors(unsigned int shaderId, GLenum shaderType);
  unsigned int compileShader(GLenum shaderType, const char *shaderCode);
  void checkProgramCompileErrors(unsigned int programId);
  unsigned int compileProgram(unsigned int vertId, unsigned int fragId);
public:
  Shader(){}
  void compile(const char *vertShaderCode, const char *fragShaderCode);
  void clear();
  void use();
  void setInt(const char *name, int value);
  void setVec3(const char *name, glm::vec3 value);
  void setMat4(const char *name, glm::mat4 value);
};

#endif
