//
//  Sound.h
//  linkSDL
//
//  Created by Thiago Dantas on 21/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef Sound_h
#define Sound_h

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER


#include <stdio.h>
#include "../include/GameObject.h"
#include "../include/Component.h"
#include "../include/SDL_include.h"

class Sound : public Component{
public:
    Sound(GameObject& associated);
    Sound(GameObject& associated, std::string file);
    ~Sound();
    void Play(int times = 1);
    void Stop();
    void Open(std::string file);
    bool IsOpen();
    
    // Adicionada para controlar destructor de som.
    bool IsPlaying();
    
    // Override Component
    void Update(float dt);
    void Render();
    bool Is(std::string type);
    // Utility
    
private:
    Mix_Chunk* chunk;
    int channel;
};

#endif /* Sound_h */
