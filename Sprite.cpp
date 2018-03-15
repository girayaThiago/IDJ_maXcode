//
//  Sprite.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//


#include "Sprite.h"
#include "Game.h"

Sprite::Sprite(){
//    std::cout << "Init Sprite()\n";
    texture = nullptr;
}

Sprite::Sprite(const char* file){
//    std::cout << "Init Sprite(file)\n";
    texture = nullptr;
    Open(file);
}

Sprite::~Sprite(){
    SDL_DestroyTexture(texture);
}


void Sprite::Open(const char* file){
//    std::cout << "Sprite::Open(file)" << std::endl;

    /// se já houver uma textura destruir para alocar uma nova;
    if (texture != nullptr) {
        SDL_DestroyTexture(texture);
        texture = nullptr;
    }

    texture = IMG_LoadTexture(Game::GetInstance()->GetRenderer(), file);
    if (texture == nullptr) {
        std::cout << "error loading texture SDL Error: " << SDL_GetError() << std::endl;
        exit(-1);
    }

    
    /// textura alocada, descobrir tamanho e atualizar clipRect
    SDL_QueryTexture(texture, nullptr, nullptr, &width, &height);
    SetClip(0,0,width,height); // x e y, não foi especificado usando 0,0 por enquanto.
}

void Sprite::SetClip(int x, int y,
                     int w, int h){
    clipRect.x = x;
    clipRect.y = y;

    clipRect.w = w;
    clipRect.h = h;
}

void Sprite::Render(int x, int y){
    SDL_Rect dst;
    dst.x = x;
    dst.y = y;
    dst.w = clipRect.w;
    dst.h = clipRect.h;
    SDL_RenderCopy(Game::GetInstance()->GetRenderer(), texture, &clipRect, &dst);
}

int Sprite::GetWidth(){
    return width;
}

int Sprite::GetHeight(){
    return height;
}

bool Sprite::IsOpen(){
    return texture != nullptr ? true : false;
}
