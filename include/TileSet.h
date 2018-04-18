//
//  TileSet.h
//  linkSDL
//
//  Created by Thiago Dantas on 11/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef TileSet_h
#define TileSet_h

#define INCLUDE_SDL
#define INCLUDE_SDL_IMAGE

#include <iostream>
#include <string>
#include <memory>
#include "../include/GameObject.h"
#include "../include/Sprite.h"
#include "SDL_include.h"


class TileSet {
public:
    TileSet(GameObject& associated, int tileWidth, int tileHeight, std::string filename);
    
    void RenderTile(unsigned int index, float x, float y);
    
    int GetTileWidth();
    int GetTileHeight();
private:
    
    Sprite tileSet;
//    std::shared_ptr<SDL_Texture> tileSet;
    int rows;
    int columms;
    
    int tileWidth;
    int tileHeight;
    
};

#endif /* TileSet_h */
