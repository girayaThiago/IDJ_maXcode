//
//  Music.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//


#include "../include/Music.h"
#include "../include/Resources.h"

Music::Music(){
    music = nullptr;
}

Music::Music(const char* file){
    music = nullptr;
    Open(file);
}

void Music::Play(int times){
    if (music != nullptr){
        Mix_PlayMusic(music, times);
    }
}

void Music::Stop(int msToStop){
    Mix_FadeOutMusic(msToStop);
}

void Music::Open(const char* file){
    if (music != nullptr){
        Stop();
    }
  music = Resources::GetMusic(file);
}

bool Music::IsOpen(){
    return music != nullptr ? true : false;
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}
