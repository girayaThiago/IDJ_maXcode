//
//  TileMap.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 13/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/TileMap.h"

TileMap::TileMap(GameObject &associated, std::string file, TileSet* tileSet) : Component(associated){
  Load(file);
  this->tileSet = tileSet;
}

void TileMap::Load(std::string file){
  std::fstream input;
  char virgula;
  int parametro;
  input.open(file);
  
  input >> mapWidth >> virgula >> mapHeight >> virgula >> mapDepth >> virgula;
  printf("Map width = %d\n", mapWidth);
  printf("Map height = %d\n", mapHeight);
  printf("Map depth = %d\n", mapDepth);
  while (!input.eof()){
    input >> parametro >> virgula;
    
    tileMatrix.emplace_back(parametro-1);
  }
  
}
void TileMap::SetTileSet(TileSet* tileSet){
  this->tileSet = tileSet;
}
int& TileMap::At(int x,int  y,int z){
  
  int index = x + (y * mapWidth)+ (z * mapWidth * mapHeight);
//  printf("indice calculado = %d\n", index);
  return tileMatrix[index];
}
// Override
void TileMap::Render(){
  for (int i = 0; i < mapDepth; i++){
    RenderLayer(i);
  }
}

void TileMap::Update(float dt){
  
}

void TileMap::RenderLayer (int layer, int cameraX, int cameraY){
  for (int y = 0; y < mapHeight; y++){
    for (int x = 0; x < mapWidth; x++){
      tileSet->RenderTile(At(x,y,layer),  x*tileSet->GetTileWidth() - cameraX, y*tileSet->GetTileHeight() - cameraY);
    }
  }
}

int TileMap::GetWidth(){
  return mapWidth;
}
int TileMap::GetHeight(){
  return mapHeight;
}
int TileMap::GetDepth(){
  return mapDepth;
}

bool TileMap::Is(std::string type){
  return (type.compare("TileMap") == 0) ? true : false;
}
