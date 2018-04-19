//
//  Game.h
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#pragma once

#ifndef Game_h
#define Game_h

#include <iostream>
#include <string>
#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL_IMAGE
#include "../include/State.h"
#include "../include/SDL_include.h"

class Game{
private:
  static Game* instance;
  SDL_Window* window;
  SDL_Renderer* renderer;
  State* state;
  Game(std::string title, int width, int height);

  uint32_t frameStart;
  float dt;
  void CalculateDeltaTime();
  
public:
  ~Game();
  static Game& GetInstance();
  void Run();
  State* GetState();
  SDL_Renderer* GetRenderer();
  
  float GetDeltaTime();
};

#endif /* Game_h */
