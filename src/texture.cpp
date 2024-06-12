#include "texture.hpp"

void Texture::generate(unsigned int width, unsigned int height, unsigned int nrChannels, unsigned char *data){
  this->width = width, this->height = height;
  format = nrChannels == 3 ? GL_RGB : GL_RGBA;

  glGenTextures(1, &id);
  glBindTexture(GL_TEXTURE_2D, id);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

  glTexImage2D(GL_TEXTURE_2D, 0, format, width, height, 0, format, GL_UNSIGNED_BYTE, data);
  glGenerateMipmap(GL_TEXTURE_2D);

  glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::clear(){
  glDeleteTextures(1, &id);
}

void Texture::bind(){
  glBindTexture(GL_TEXTURE_2D, id);
}
