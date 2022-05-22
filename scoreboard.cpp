#include <SDL.h>
#include "Object.h"

Obj back_sm, clear_sm, backgroundSB;
SDL_Renderer * ren_sb = NULL;
SDL_Surface * surf_sb = NULL;
bool running_sb = true;
void input_sb() {
  while (SDL_PollEvent( & e)) {
    SDL_GetMouseState( & mousex, & mousey);
    if (e.type == SDL_QUIT) {
      running_sb = false;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if (e.key.keysym.sym == SDLK_ESCAPE) {
        running_sb = false;
        windowloop = false;
        SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex >= back_sm.dest.x) && (mousex <= back_sm.dest.x + back_sm.dest.w) && (mousey >= back_sm.dest.y) && (mousey <= back_sm.dest.y + back_sm.dest.h)) {
        switch (lastpage) {
        case 0:
          status = 0;
          break;
        case 1:
          status = 3;
          break;
        }
        SDL_DestroyRenderer(ren_sb);
        running_sb = false;
        return;
        // Open The Game Page
      }
      if ((mousex >= clear_sm.dest.x) && (mousex <= clear_sm.dest.x + clear_sm.dest.w) && (mousey >= clear_sm.dest.y) && (mousey <= clear_sm.dest.y + clear_sm.dest.h)) {
        if (openfile(true)) {
          Mix_PlayChannel(-1, clearscore_sound, 0);
        } else {
          cout << "ERROR RESETING SCORES";
        }
      }
    }
  }
}
// 0 = firstmenu | 1 = lastmenu
void scoreboard() {
  running_sb = true;
  bool showingscore = false;
  returnscore();
  ren_sb = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  string playerinfo[10];
  SDL_Rect rect_sb;
  rect_sb.x = 0;
  rect_sb.y = 0;
  rect_sb.w = 350;
  rect_sb.h = 600;
  //background
  backgroundSB.setDest(0, 0, 350, 600);
  backgroundSB.setSource(0, 0, 2000, 2000);
  backgroundSB.setImage("data/4.png", ren_sb);
  // back
  back_sm.setDest(50, 500, 100, 100);
  back_sm.setSource(0, 0, 512, 512);
  back_sm.setImage("data/back.png", ren_sb);
  // clearscore
  clear_sm.setDest(250, 500, 100, 100);
  clear_sm.setSource(0, 0, 500, 500);
  clear_sm.setImage("data/highscore_setting.png", ren_sb);
  TTF_Init();

  float rot = 0;
  while (running_sb) {
    int framecount = 0;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0;
    if (lastframe >= lasttime + 1000) {
      lasttime = lastframe;
      framecount = 0;
    }
    if (showingscore == 0) {
      for (int i = 0; i < 10; i++) {
        playerinfo[i] = to_string(i + 1) + "." + player[i].name + ": " + to_string(player[i].score);
        cout << playerinfo[i] << endl;
      }
      showingscore = 1;
    }
    SDL_SetRenderDrawColor(ren_sb, 255, 255, 255, 255);
    SDL_RenderFillRect(ren_sb, & rect_sb);

    SDL_RenderCopyEx(ren_sb, backgroundSB.tex, & backgroundSB.src, & backgroundSB.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sb, back_sm.tex, & back_sm.src, & back_sm.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sb, clear_sm.tex, & clear_sm.src, & clear_sm.dest, 0, NULL, SDL_FLIP_NONE);

    rot += 2;
    framecount++;
    int timerFPS = SDL_GetTicks() - lastframe;
    if (timerFPS < (1000 / 90)) {
      SDL_Delay((1000 / 90) - timerFPS);
    }
    register int i = 0;
    while (i < 10) {
      WriteMessage(playerinfo[i].c_str(), 18, 10 + i * 35, 155, 0, 0, 35, ren_sb);
      i++;
    }
    SDL_RenderPresent(ren_sb);
    input_sb();
  }
}
