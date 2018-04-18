//
//  InputManager.h
//  linkSDL
//
//  Created by Thiago Dantas on 18/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef InputManager_h
#define InputManager_h

#define LEFT_ARROW_KEY SDLK_LEFT
#define RIGHT_ARROW_KEY SDLK_RIGHT
#define UP_ARROW_KEY SDLK_UP
#define DOWN_ARROW_KEY SDLK_DOWN
#define SPACE_KEY SDLK_SPACE
#define ESCAPE_KEY SDLK_ESCAPE
#define LEFT_MOUSE_BUTTON SDL_BUTTON_LEFT


#include <stdio.h>
#include <unordered_map>

class InputManager {
public:
  void Update();
  
  bool KeyPress (int key);
  bool KeyRelease (int key);
  bool IsKeyDown (int key);
  
  bool MousePress (int button);
  bool MouseRelease (int button);
  bool IsMouseDown (int button);
  
  int GetMouseX();
  int GetMouseY();
  
  bool QuitRequested();
  
  static InputManager& GetInstance(){
    static InputManager instance = InputManager();
    return instance;
  }
  
private:
  InputManager();
  ~InputManager();
  
  bool mouseState[6];
  int mouseUpdate[6];
  
  std::unordered_map<int, bool> keyState;
  std::unordered_map<int, int> keyUpdate;
  
  
  bool quitRequested;
  
  int updateCounter;
  
  int mouseX;
  int mouseY;
  
};

#endif /* InputManager_h */
