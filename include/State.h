//
//  State.h
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef State_h
#define State_h

#define INCLUDE_SDL

#include <memory>
#include <vector>
//#include "../include/Sprite.h" //utilizado apenas no .cpp comentado;
#include "../include/Music.h"
#include "../include/GameObject.h"
//#include "../include/TileMap.h" //utilizado apenas no .cpp comentado;
#include "../include/SDL_include.h"
#include "../include/Camera.h"


class State{
private:
  std::vector<std::shared_ptr<GameObject>> objectArray;
  Music music;
  bool started;
  bool quitRequested;

public:
  State();
  ~State();
  
  void Start();
  std::weak_ptr<GameObject> AddObject(GameObject* go);
  std::weak_ptr<GameObject> GetObjectPtr(GameObject* go);
//  void AddObject(int mouseX, int mouseY);
  bool QuitRequested();
  void LoadAssets();
  void Update(float dt);
  void Render();
};

#endif /* State_h */
