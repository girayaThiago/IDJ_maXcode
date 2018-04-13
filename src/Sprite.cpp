//
//  Sprite.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//


#include "../include/Sprite.h"
#include "../include/Game.h"
#include "../include/Resources.h"
#include <memory>

Sprite::Sprite(GameObject& associated) : Component(associated){
    this->texture = nullptr;
}

Sprite::Sprite(GameObject& associated, std::string file) : Component(associated){
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}


void Sprite::Open(std::string file){
    texture = Resources::GetImage(file);
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0,0,width,height);
}

void Sprite::SetClip(int x, int y, int w, int h){
    clipRect.x = x;
    clipRect.y = y;
    clipRect.w = w;
    clipRect.h = h;
  
    associated.box.w = w;
    associated.box.h = h;
    
}

void Sprite::Render(){
    Render(associated.box.x, associated.box.y);
}

void Sprite::Render(int x, int y){
    SDL_Rect dst;
    
    dst.x = x;
    dst.y = y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance().GetRenderer(), texture, &clipRect, &dst);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

void Sprite::Update(float dt) {
    
}

bool Sprite::Is(std::string type){
    return (type.compare("Sprite") == 0) ? true : false;
}

bool Sprite::IsOpen(){
    return texture != nullptr ? true : false;
}
