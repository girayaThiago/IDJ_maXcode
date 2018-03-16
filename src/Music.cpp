//
//  Music.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//


#include "../include/Music.h"

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
        Mix_FreeMusic(music);
    }
    music = Mix_LoadMUS(file);
    if (music == nullptr){
        std::cout << "error loading music: " << file << std::endl;
        exit(-1);
    }
}

bool Music::IsOpen(){
    return music != nullptr ? true : false;
}

Music::~Music(){
    Stop();
    Mix_FreeMusic(music);
}
