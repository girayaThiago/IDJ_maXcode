//
//  Game.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
const int WIDTH = 1024, HEIGHT = 600;
//#include "Game.h"
#include "../include/Game.h"
#include "../include/InputManager.h"

Game* Game::instance = nullptr;

Game::Game(std::string title, int width, int height){
  /// Initializing SDL
  if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO | SDL_INIT_TIMER ) != 0){
    std::cout << "Error initializing! SDL Error: " << SDL_GetError() << std::endl;
    exit(-1);
  }
  /// Initializing SDL_image
  if (IMG_Init(IMG_INIT_PNG | IMG_INIT_JPG | IMG_INIT_TIF) == 0){
    std::cout << "Error initializing SDL_image Image Error:" << IMG_GetError() << std::endl;
    exit(-1);
  }
  /// Initializing SDL_mixer
  Mix_Init(MIX_INIT_OGG);
  if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 1024) != 0){
    std::cout << "Error initializing Mix_OpenAudio Mix Error: " << Mix_GetError() << std::endl;
    exit(-1);
  }
  Mix_AllocateChannels(32);
  this->window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, 0);
  if (window == nullptr) {
    std::cout << "Error creating SDL_Window!" << std::endl;
    exit(-1);
  }

  renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
  if (renderer == nullptr){
    std::cout << "Error creating Renderer!" << std::endl;
    exit(-1);
  }
  frameStart = 0;
  dt = 0;
  state = new State();
}

Game::~Game() {
  Mix_CloseAudio();
  Mix_Quit();
  IMG_Quit();
  SDL_DestroyRenderer(renderer);
  SDL_DestroyWindow(window);
  SDL_Quit();
}

State* Game::GetState() {
  return state;
}

SDL_Renderer* Game::GetRenderer(){
  return renderer;
}

Game& Game::GetInstance() {
  if (instance == nullptr) {
    instance = new Game("Thiago Dantas 14/0170961", WIDTH, HEIGHT);
  }
  return *instance;
}

void Game::Run(){
  state->LoadAssets();
  
  while (state->QuitRequested() == false){
    CalculateDeltaTime();
    InputManager::GetInstance().Update();
    state->Update(GetDeltaTime());
    state->Render();
    SDL_RenderPresent(renderer);
    SDL_Delay(33);
  }
}

void Game::CalculateDeltaTime(){
  dt = SDL_GetTicks() - frameStart;
  dt /= 1000; // converter em segundos;
  frameStart = SDL_GetTicks(); // aribui o valor do frame atual para frameStart
}

float Game::GetDeltaTime(){
  return dt;
}
