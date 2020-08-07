#ifndef RENDERER_H
#define RENDERER_H

#include <vector>
#include "SDL.h"
#include "snake.h"

class Renderer {
 public:
  Renderer(const std::size_t screen_width, const std::size_t screen_height,
           const std::size_t grid_width, const std::size_t grid_height, bool change_theme);
  ~Renderer();

  virtual void Render(Snake const snake, SDL_Point const &food);
  void UpdateWindowTitle(int score, int fps);
  //Getters
  std::size_t GetScreenWidth()const{return screen_width;}
  std::size_t GetScreenHeight()const{return screen_height;}
  std::size_t GetGridWidth()const{return grid_width;}
  std::size_t GetGridHeight()const{return grid_height;}
  SDL_Renderer* GetSDLRenderer()const{return sdl_renderer;}
  SDL_Window*  GetSDLWindow()const{return sdl_window;}
 private:
  SDL_Window *sdl_window;
  SDL_Renderer *sdl_renderer;
  
  const std::size_t screen_width;
  const std::size_t screen_height;
  const std::size_t grid_width;
  const std::size_t grid_height;
  bool _change_theme;
};

#endif