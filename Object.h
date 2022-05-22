#ifndef OBJ_H
#define OBJ_H

#include <string.h>

class Obj {
  public:
    SDL_Rect dest;
  SDL_Rect src;
  SDL_Texture * tex;
  void setDest(int x, int y, int w, int h) {
    dest.x = x;
    dest.y = y;
    dest.w = w;
    dest.h = h;
  }
  void setSource(int x, int y, int w, int h) {
    src.x = x;
    src.y = y;
    src.w = w;
    src.h = h;
  }
  void setImage(string filename, SDL_Renderer * ren) {
    SDL_Surface * surf = IMG_Load(filename.c_str());
    tex = SDL_CreateTextureFromSurface(ren, surf);
  }
};

#endif
