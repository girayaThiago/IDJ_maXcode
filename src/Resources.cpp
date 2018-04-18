//
//  Resources.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 13/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Resources.h"
#include "../include/Game.h"

std::unordered_map<std::string, SDL_Texture*> Resources::imageTable;
std::unordered_map<std::string, Mix_Music*> Resources::musicTable;
std::unordered_map<std::string, Mix_Chunk*> Resources::soundTable;

SDL_Texture* Resources::GetImage(std::string file){
  if (imageTable[file] == nullptr){
    imageTable[file] = IMG_LoadTexture(Game::GetInstance().GetRenderer(), file.c_str());
    if (imageTable[file] == nullptr) {
      std::cout << "error loading texture SDL Error: " << SDL_GetError() << std::endl;
      exit(-1);
    }
  }
  return imageTable[file];
}

void Resources::ClearImages(){
  for (auto itr = imageTable.begin(); itr != imageTable.end(); itr++){
    SDL_DestroyTexture(itr->second);
  }
  imageTable.clear();
}

Mix_Music* Resources::GetMusic(std::string file){
  if (musicTable[file] == nullptr){
    musicTable[file] = Mix_LoadMUS(file.c_str());
    if (musicTable[file] == nullptr){
      std::cout << "error loading music: " << file << std::endl;
      exit(-1);
    }
  }
  return musicTable[file];
}

void Resources::ClearMusics(){
  for (auto itr = musicTable.begin(); itr != musicTable.end(); itr++){
    Mix_FreeMusic(itr->second);
  }
  musicTable.clear();
}

Mix_Chunk* Resources::GetSound(std::string file){
  if (soundTable[file] == nullptr){
    soundTable[file] = Mix_LoadWAV(file.c_str());
    if (soundTable[file] == nullptr){
      std::cout << "error loading sound: " << file << std::endl;
      exit(-1);
    }
    
  }
  return soundTable[file];
}

void Resources::ClearSounds(){
  for (auto itr = soundTable.begin(); itr != soundTable.end(); itr++){
    Mix_FreeChunk(itr->second);
  }
  soundTable.clear();
}
