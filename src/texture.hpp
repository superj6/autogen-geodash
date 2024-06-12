#ifndef TEXTURE_H
#define TEXTURE_H

#include <glad/glad.h>

class Texture{
private:
  unsigned int id;
  unsigned int width, height;
  unsigned int format;
public:
  Texture(){}
  void generate(unsigned int width, unsigned int height, unsigned int nrChannels, unsigned char *data);
  void clear();
  void bind();
};

#endif
