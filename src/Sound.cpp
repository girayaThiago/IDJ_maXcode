//
//  Sound.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 21/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include <iostream>
#include "../include/Game.h"
#include "../include/Sound.h"
#include "../include/Resources.h"

//void ChannelDone(int channel){
////    associated.RequestDelete();
//}

Sound::Sound(GameObject& associated) : Component(associated){
    chunk = nullptr;
    Mix_ChannelFinished([](int channel){
        printf("channel %d finished\n", channel);
    });
}
Sound::Sound(GameObject& associated, std::string file) : Sound(associated){
    Open(file);
}

Sound::~Sound(){
    if (chunk != nullptr){
        Mix_HaltChannel(channel);
        Mix_FreeChunk(chunk);
    }
}

void Sound::Play(int times){
    channel = Mix_PlayChannel(-1, chunk, times-1);
}

void Sound::Stop(){
    if (chunk){
        Mix_HaltChannel(channel);
    }
}

void Sound::Open(std::string file){
  chunk = Resources::GetSound(file);
}

bool Sound::IsOpen(){
    return chunk ? true : false;
}

bool Sound::IsPlaying(){
    return Mix_Playing(this->channel);
}

void Sound::Update(float dt){
    
}

void Sound::Render(){
    
}

bool Sound::Is(std::string type){
    return (type.compare("Sound") == 0) ? true : false;
    
}
