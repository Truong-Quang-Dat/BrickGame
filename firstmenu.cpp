#include <SDL.h>
#include "Object.h"

Obj play, high, ball, settings, backgroundFM;
SDL_Renderer * ren_fm = NULL;
SDL_Surface * surf_fm = NULL;
int lastpage;
bool running_fm = true;
class ball_image_class {
  public:
    string ball_image_path;
  int source_w;
  int source_h;
};
vector < ball_image_class > ball_image;
int ball_image_number = 0;

void WriteMessage(const char * msg, int x, int y, int r, int g, int b, int size, SDL_Renderer * ren_fm) {
  TTF_Init();
  TTF_Font * font = TTF_OpenFont("data/font3.ttf", size);
  SDL_Color color_fm;
  color_fm.r = r;
  color_fm.g = g;
  color_fm.b = b;
  color_fm.a = 255;
  SDL_Rect rect_fm;
  surf_fm = TTF_RenderText_Solid(font, msg, color_fm);
  tex = SDL_CreateTextureFromSurface(ren_fm, surf_fm);
  rect_fm.x = x;
  rect_fm.y = y;
  rect_fm.w = surf_fm -> w;
  rect_fm.h = surf_fm -> h;
  TTF_CloseFont(font);
  TTF_Quit();
  SDL_FreeSurface(surf_fm);
  SDL_RenderCopy(ren_fm, tex, NULL, & rect_fm);
  SDL_DestroyTexture(tex);
}
void input_fm() {
  while (SDL_PollEvent( & e) == true && status != 4) {
    SDL_GetMouseState( & mousex, & mousey);
    if (e.type == SDL_QUIT && status != 4) {
      running_fm = false;
      windowloop = false;
      SDL_Quit();
      return;
    }
    if (e.type == SDL_KEYDOWN && status != 4) {
      if (e.key.keysym.sym == SDLK_ESCAPE) {
        running_fm = false;
        windowloop = false;
        SDL_Quit();
        return;
      }
    }
    if (e.type == SDL_MOUSEBUTTONDOWN) {
      if ((mousex >= play.dest.x) && (mousex <= play.dest.x + play.dest.w) && (mousey >= play.dest.y) && (mousey <= play.dest.y + play.dest.h)) {
        status = 2;
        SDL_DestroyRenderer(ren_fm);
        running_fm = false;
        return;
      }
      if ((mousex >= settings.dest.x) && (mousex <= settings.dest.x + settings.dest.w) && (mousey >= settings.dest.y) && (mousey <= settings.dest.y + settings.dest.h)) {
        status = 1;
        SDL_DestroyRenderer(ren_fm);
        running_fm = false;
        return;
      }
      if ((mousex >= ball.dest.x) && (mousex <= ball.dest.x + ball.dest.w) && (mousey >= ball.dest.y) && (mousey <= ball.dest.y + ball.dest.h)) {
        ball_image_number++;

        if (ball_image_number > 4)
          ball_image_number = 0;
        ball.setSource(0, 0, ball_image[ball_image_number].source_w, ball_image[ball_image_number].source_h);
        ball.setImage(ball_image[ball_image_number].ball_image_path, ren_fm);
        cout << "ball changed" << endl;
      }
      if ((mousex >= high.dest.x) && (mousex <= high.dest.x + high.dest.w) && (mousey >= high.dest.y) && (mousey <= high.dest.y + high.dest.h)) {
        status = 5;
        lastpage = 0;
        SDL_DestroyRenderer(ren_fm);
        running_fm = false;
        return;
      }
    }
  }
}
void firstmenu() {
  //startaudio();
  if (ifback) {
    reset_game(false);
  }
  ball_image.push_back(ball_image_class());
  ball_image.push_back(ball_image_class());
  ball_image.push_back(ball_image_class());
  ball_image.push_back(ball_image_class());
  ball_image.push_back(ball_image_class());
  ball_image[0].ball_image_path = "data/BlueBall.png";
  ball_image[1].ball_image_path = "data/ball2.png";
  ball_image[2].ball_image_path = "data/ball3.png";
  ball_image[3].ball_image_path = "data/ball4.png";
  ball_image[4].ball_image_path = "data/ball5.png";
  ball_image[0].source_w = 715;
  ball_image[0].source_h = 715;
  ball_image[1].source_w = 2787;
  ball_image[1].source_h = 2713;
  ball_image[2].source_w = 600;
  ball_image[2].source_h = 600;
  ball_image[3].source_w = 1210;
  ball_image[3].source_h = 883;
  ball_image[4].source_w = 1000;
  ball_image[4].source_h = 1000;

  running_fm = true;
  ren_fm = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
  SDL_Rect rect_fm;
  rect_fm.x = 0;
  rect_fm.y = 0;
  rect_fm.w = 350;
  rect_fm.h = 600;
  //background
  backgroundFM.setDest(0, 0, 350, 600);
  backgroundFM.setSource(0, 0, 1500, 1500);
  backgroundFM.setImage("data/1.png", ren_fm);
  // play
  play.setDest(100, 225, 150, 150);
  play.setSource(0, 0, 2000, 2000);
  play.setImage("data/play.png", ren_fm);
  // settings
  settings.setDest(120, 480, 100, 100);
  settings.setSource(0, 0, 1500, 1500);
  settings.setImage("data/setting3.png", ren_fm);
  // high
  high.setDest(230, 475, 80, 80);
  high.setSource(0, 0, 512, 512);
  high.setImage("data/HighScore.png", ren_fm);
  // ball
  ball.setDest(50, 490, 70, 70);
  ball.setSource(0, 0, ball_image[ball_image_number].source_w, ball_image[ball_image_number].source_h);
  ball.setImage(ball_image[ball_image_number].ball_image_path, ren_fm);
  TTF_CloseFont(font);
  TTF_Quit();
  float hei = 0;
  bool down = true;
  float sh = 2.2;
  float pos = 0;
  float rot = 0;
  while (running_fm) {
    int framecount = 0;
    int lastframe = SDL_GetTicks();
    static int lasttime = 0;
    if (lastframe >= lasttime + 1000) {
      lasttime = lastframe;
      framecount = 0;
    }
    rot += 2;
    SDL_SetRenderDrawColor(ren_fm, 255, 255, 255, 255);
    SDL_RenderFillRect(ren_fm, & rect_fm);
    SDL_RenderCopyEx(ren_fm, backgroundFM.tex, & backgroundFM.src, & backgroundFM.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_fm, play.tex, & play.src, & play.dest, 0 + rot, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_fm, settings.tex, & settings.src, & settings.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_fm, high.tex, & high.src, & high.dest, 0, NULL, SDL_FLIP_NONE);
    SDL_RenderCopyEx(ren_fm, ball.tex, & ball.src, & ball.dest, 0 + rot, NULL, SDL_FLIP_NONE);
    //rot += 2;
    srand(time(NULL));
    if (down) {
      WriteMessage("Swipe Brick Breaker", 50, 10 + hei, 240, rand() % 100 + 30, rand() % 100 + 30, 35, ren_fm);
    } else {
      WriteMessage("Swipe Brick Breaker", 50, 10 + hei, 230, rand() % 100 + 30, rand() % 100 + 30, 35, ren_fm);
    }
    pos = 10 + hei;
    if (down) {
      if (pos >= 150) {
        down = false;
        hei -= sh;
      } else {
        hei += sh;
      }
    } else {
      if (pos <= 30) {
        down = true;
        hei += sh;
      } else {
        hei -= sh;
      }
    }
    framecount++;
    int timerFPS = SDL_GetTicks() - lastframe;
    if (timerFPS < (1000 / 50)) {
      SDL_Delay((1000 / 50) - timerFPS);
    }
    SDL_RenderPresent(ren_fm);
    input_fm();
  }
}
