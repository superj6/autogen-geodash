#include "shader.hpp"

#include <iostream>

void Shader::checkShaderCompileErrors(unsigned int shaderId, GLenum type){
  int success;
  char infoLog[1024];

  glGetShaderiv(shaderId, GL_COMPILE_STATUS, &success);
  if(!success){
    glGetShaderInfoLog(shaderId, 1024, NULL, infoLog);
    std::cout << "| ERROR::SHADER: Compile-time error: Type: " << type << "\n"
      << infoLog << "\n -- --------------------------------------------------- -- "
      << std::endl;
  }
}

unsigned int Shader::compileShader(GLenum shaderType, const char *shaderCode){
  unsigned int shaderId = glCreateShader(shaderType);

  glShaderSource(shaderId, 1, &shaderCode, NULL);
  glCompileShader(shaderId);
  checkShaderCompileErrors(shaderId, shaderType);

  return shaderId;
}

void Shader::checkProgramCompileErrors(unsigned int programId){
  int success;
  char infoLog[1024];

  glGetProgramiv(programId, GL_LINK_STATUS, &success);
  if(!success){
    glGetProgramInfoLog(programId, 1024, NULL, infoLog);
    std::cout << "| ERROR::Shader: Link-time error: Type: PROGRAM" << "\n"
      << infoLog << "\n -- --------------------------------------------------- -- "
      << std::endl;
  }
}

unsigned int Shader::compileProgram(unsigned int vertId, unsigned int fragId){
  unsigned int programId = glCreateProgram();

  glAttachShader(programId, vertId);
  glAttachShader(programId, fragId);
  
  glLinkProgram(programId);
  checkProgramCompileErrors(programId);

  return programId;
}

void Shader::compile(const char *vertShaderCode, const char *fragShaderCode){
  unsigned int vertId, fragId;
  vertId = compileShader(GL_VERTEX_SHADER, vertShaderCode);
  fragId = compileShader(GL_FRAGMENT_SHADER, fragShaderCode);

  id = compileProgram(vertId, fragId);

  glDeleteShader(vertId);
  glDeleteShader(fragId);
}

void Shader::clear(){
  glDeleteProgram(id);
}

void Shader::use(){
  glUseProgram(id);
}

void Shader::setInt(const char *name, int value){
  glUniform1i(glGetUniformLocation(id, name), value);
}

void Shader::setVec3(const char *name, glm::vec3 value){
  glUniform3fv(glGetUniformLocation(id, name), 1, &value[0]);
}

void Shader::setMat4(const char *name, glm::mat4 value){
  glUniformMatrix4fv(glGetUniformLocation(id, name), 1, GL_FALSE, &value[0][0]);
}
