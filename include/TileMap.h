//
//  TileMap.h
//  linkSDL
//
//  Created by Thiago Dantas on 13/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef TileMap_h
#define TileMap_h

#include "../include/TileSet.h"
#include "../include/Component.h"
#include <fstream>

class TileMap: public Component {
public:
  TileMap(GameObject &associated, std::string file, TileSet* tileSet);
  void Load(std::string file);
  void SetTileSet(TileSet* tileSet);
  int& At(int x,int  y,int z = 0);
  
  void Render(); // Override Component;
  bool Is(std::string type); // Override Component;
  void Update(float dt); // Override Compoennt;
  void RenderLayer (int layer,
                    int cameraX = 0,
                    int cameraY = 0);
  int GetWidth();
  int GetHeight();
  int GetDepth();
private:
  std::vector<int> tileMatrix;
  TileSet* tileSet;
  int mapWidth;
  int mapHeight;
  int mapDepth;
};

#endif /* TileMap_h */
