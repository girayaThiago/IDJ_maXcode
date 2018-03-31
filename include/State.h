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

#include <vector>
#include <memory>
#include "../include/Sprite.h"
#include "../include/Music.h"
#include "../include/SDL_include.h"
#include "../include/GameObject.h"

class State{
private:
    Sprite bg;
    std::vector<std::unique_ptr<GameObject>> objects;
    Music music;
    bool quitRequested;

public:
    State();
    ~State();
    
    void Input();
    void AddObject(int mouseX, int mouseY);
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
    
};

#endif /* State_h */
