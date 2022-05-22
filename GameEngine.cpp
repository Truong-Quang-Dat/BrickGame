#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL.h>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
void reset_game(bool ifrun);
bool ifback = false;
bool ifend = false;

#include "Object.h"

SDL_Window * win = NULL;
SDL_Texture * tex = NULL;
int status = 0;
Mix_Music * music = NULL;
SDL_Event e;
int mousex, mousey;
string playername;
TTF_Font * font = NULL;
int playerscore;
bool windowloop = true;

#include "audiomanager.cpp"
#include "highscore.cpp"
#include "firstmenu.cpp"
#include "settingsmenu.cpp"
#include "game.cpp"
#include "lastmenu.cpp"
#include "scoreboard.cpp"

int main(int argc, char * args[]) {
  srand(time(NULL));
  SDL_Init(SDL_INIT_EVERYTHING);
  TTF_Init();
  File_Init();
  Music_Init();
  win = SDL_CreateWindow("Ball_Brick", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 350, 600, 0);
  startaudio();
  TTF_CloseFont(font);
  TTF_Quit();
  while (windowloop) {
    switch (status) {
    case 0:
      firstmenu();
      break;
    case 1:
      settingsmenu();
      break;
    case 2:
      game();
      break;
    case 3:
      lastmenu();
      break;
    case 5:
      scoreboard();
      break;
    default:
      SDL_Quit();
    }

  }
  return 0;
}
