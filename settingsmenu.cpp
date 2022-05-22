#include <SDL.h>
#include "Object.h"

Obj sound_sm, clearscore_sm, ball_sm, backgroundSM;
int mousex_sm, mousey_sm;
SDL_Renderer * ren_sm;
bool smenu = true;
void input_sm() {
  while (SDL_PollEvent( & e)) {
    SDL_GetMouseState( & mousex_sm, & mousey_sm);
    if (e.type == SDL_QUIT) {
      smenu = false;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN) {
      if (e.key.keysym.sym == SDLK_ESCAPE) {
        smenu = false;
        windowloop = false;
        SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex_sm >= sound_sm.dest.x) && (mousex_sm <= sound_sm.dest.x + sound_sm.dest.w) && (mousey_sm >= sound_sm.dest.y) && (mousey_sm <= sound_sm.dest.y + sound_sm.dest.h)) {
        cout << "Audio Clicked" << endl;
        bool musicstatus = checkaudio();
        if (musicstatus) {
          stopaudio();
        } else {
          startaudio();
        }
      }

      if ((mousex_sm >= clearscore_sm.dest.x) && (mousex_sm <= clearscore_sm.dest.x + clearscore_sm.dest.w) && (mousey_sm >= clearscore_sm.dest.y) && (mousey_sm <= clearscore_sm.dest.y + clearscore_sm.dest.h)) {
        cout << "Clear Highscore Clicked" << endl;
        openfile(true);
        cout << "High score cleared" << endl;
      }
      if ((mousex_sm >= ball_sm.dest.x) && (mousex_sm <= ball_sm.dest.x + ball_sm.dest.w) && (mousey_sm >= ball_sm.dest.y) && (mousey_sm <= ball_sm.dest.y + ball_sm.dest.h)) {
        SDL_DestroyRenderer(ren_sm);
        smenu = false;
        status = 0;
        return;

      }

    }
  }
}
void settingsmenu() {
  smenu = true;
  ren_sm = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect rect;
  rect.x = 0;
  rect.y = 0;
  rect.w = 350;
  rect.h = 600;
  //background
  backgroundSM.setDest(0, 0, 350, 600);
  backgroundSM.setSource(0, 0, 2000, 2000);
  backgroundSM.setImage("data/5.png", ren_sm);
  // sound_sm
  sound_sm.setDest(140, 100, 90, 90);
  sound_sm.setSource(0, 0, 1500, 1500);
  sound_sm.setImage("data/sound.png", ren_sm);
  // clearscore_sm
  clearscore_sm.setDest(140, 225, 90, 90);
  clearscore_sm.setSource(0, 0, 1500, 1500);
  clearscore_sm.setImage("data/highscore_setting.png", ren_sm);
  // ball_sm
  ball_sm.setDest(140, 475, 90, 90);
  ball_sm.setSource(0, 0, 1500, 1500);
  ball_sm.setImage("data/back_icon.png", ren_sm);

  float rot = 0;
  while (smenu) {
    int framecount = 0;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0;
    if (lastframe >= lasttime + 1000) {
      lasttime = lastframe;
      framecount = 0;
    }
    SDL_SetRenderDrawColor(ren_sm, 255, 255, 255, 255);
    SDL_RenderFillRect(ren_sm, & rect);

    SDL_RenderCopyEx(ren_sm, backgroundSM.tex, & backgroundSM.src, & backgroundSM.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sm, sound_sm.tex, & sound_sm.src, & sound_sm.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sm, clearscore_sm.tex, & clearscore_sm.src, & clearscore_sm.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_sm, ball_sm.tex, & ball_sm.src, & ball_sm.dest, 0, NULL, SDL_FLIP_NONE);
    rot += 2;

    framecount++;
    int timerFPS = SDL_GetTicks() - lastframe;
    if (timerFPS < (1000 / 60)) {
      SDL_Delay((1000 / 60) - timerFPS);
    }

    SDL_RenderPresent(ren_sm);
    input_sm();
  }
}
