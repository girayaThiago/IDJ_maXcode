//
//  TileSet.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 11/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/TileSet.h"


//int rows;
//int columms;
//
//int tileWidth;
//int tileHeight;

TileSet::TileSet(GameObject& associated,int tileWidth, int tileHeight, std::string file): tileSet(associated, file){
//    tileSet = new Sprite(associated, filename);
  
    
    
    this->tileWidth = tileWidth;
    this->tileHeight = tileHeight;
    
    rows = tileSet.GetHeight() / tileHeight;
    columms = tileSet.GetWidth() /tileWidth;

}

void TileSet::RenderTile(unsigned int index, float x, float y){
  int tiles = rows*columms;
  
  if (index != 0xffffffff) {
    if (index < tiles) {
      int linha = index / columms;
      int coluna = index % columms;
      
      tileSet.SetClip(coluna*tileWidth, linha*tileHeight, tileWidth, tileHeight);
      tileSet.Render(x,y);
    }
  }
  
}

int TileSet::GetTileWidth(){
    return this->tileWidth;
}
int TileSet::GetTileHeight(){
    return this->tileHeight;
}
