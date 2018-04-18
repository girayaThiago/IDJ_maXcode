//
//  Resources.h
//  linkSDL
//
//  Created by Thiago Dantas on 13/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef Resources_h
#define Resources_h

#define INCLUDE_SDL_TEXTURE
#define INCLUDE_SDL_MIXER
#define INCLUDE_SDL

#include "../include/SDL_include.h"
#include <string>
#include <unordered_map>
#include <stdio.h>

class Resources {
public:
  static SDL_Texture* GetImage(std::string file);
  static void ClearImages();
  static Mix_Music* GetMusic(std::string file);
  static void ClearMusics();
  static Mix_Chunk* GetSound(std::string file);
  static void ClearSounds();
private:
  static std::unordered_map<std::string, SDL_Texture*> imageTable;
  static std::unordered_map<std::string, Mix_Music*> musicTable;
  static std::unordered_map<std::string, Mix_Chunk*> soundTable;
};

#endif /* Resources_h */
