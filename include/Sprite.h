//
//  Sprite.h
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef Sprite_h
#define Sprite_h

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include <iostream>
#include "../include/Component.h"
#include "../include/SDL_include.h"


class Sprite: public Component{
private:
    SDL_Texture* texture;
    int width;
    int height;
    SDL_Rect clipRect;
public:
    Sprite(GameObject& associated);
    Sprite(GameObject& associated, std::string file);
    ~Sprite();
    
    void Open(std::string file);
    void SetClip(int x, int y,
                 int w, int h);
    int GetWidth();
    int GetHeight();
    bool IsOpen();
    
    // Override Component
    void Render ();
    void Update(float dt);
    bool Is(std::string type);
};


#endif /* Sprite_h */
