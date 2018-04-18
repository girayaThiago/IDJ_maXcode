 //
//  InputManager.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 18/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#define INCLUDE_SDL
#include "../include/InputManager.h"
#include "../include/SDL_include.h"
#include <iostream>


void InputManager::Update(){
  quitRequested = false;
  updateCounter++;
  SDL_Event e = SDL_Event();
  SDL_GetMouseState(&mouseX, &mouseY);
//  std::cout << "X = " << mouseX << " Y = " << mouseY << "\n";
  while (SDL_PollEvent(&e)){
    
    if (e.type == SDL_KEYDOWN){
      if (!e.key.repeat){
        keyState[e.key.keysym.sym] = true;
        keyUpdate[e.key.keysym.sym] = updateCounter;
      }
      
    } else if (e.type == SDL_KEYUP){
      keyState[e.key.keysym.sym] = false;
      keyUpdate[e.key.keysym.sym] = updateCounter;
      
    } else if (e.type == SDL_MOUSEBUTTONDOWN){
//      if (e.button.clicks == 1){
        mouseState[e.button.button] = true;
        mouseUpdate[e.button.button] = updateCounter;
//      }
      
    } else if (e.type == SDL_MOUSEBUTTONUP){
      mouseState[e.button.button] = false;
      mouseUpdate[e.button.button] = updateCounter;
      
    } else if (e.type == SDL_QUIT){
      quitRequested = true;
    }
  }
}

bool InputManager::KeyPress (int key){
  if (keyUpdate[key] == updateCounter){
    return IsKeyDown(key);
  }
  return false;
}

bool InputManager::KeyRelease (int key){
  // se o evento aconteceu neste frame, avalie o estado então retorna e verdadeiro ou falso;
  if (keyUpdate[key] == updateCounter){
    return !IsKeyDown(key);
  }
  // se o evento não aconteceu neste frame retorna falso;
  return false;
}
bool InputManager::IsKeyDown (int key){
  return keyState[key]; // PARA SABER SE UMA KEY TA DOWN É SÓ VER SE TA TRUE?
}

bool InputManager::MousePress (int button){
  if (mouseUpdate[button] == updateCounter){
    return IsMouseDown(button);
  }
  return false;
}
bool InputManager::MouseRelease (int button){
  if (mouseUpdate[button] == updateCounter){
    return !IsMouseDown(button);
  }
  return false;
}
bool InputManager::IsMouseDown (int button){
  return mouseState[button];
}

int InputManager::GetMouseX(){
  return mouseX;
}
int InputManager::GetMouseY(){
  return mouseY;
}

bool InputManager::QuitRequested(){
  return quitRequested;
}

InputManager::InputManager(){
  for (int i = 0 ; i < 6; i++){
    mouseState[i] = false;
    mouseUpdate[i] = 0;
  }
  updateCounter = 1;
}
InputManager::~InputManager(){
  
}
