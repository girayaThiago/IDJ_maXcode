//
//  State.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include <iostream>

#include "State.h"

State::State() {
    quitRequested = false;
//    std::cout << "State initialized" << std::endl;
    bg = Sprite();
    music = Music();

}

void State::LoadAssets() {
    printf("LoadAssets()\n");
    bg.Open("./img/ocean.jpg");
    music.Open("./audio/stageState.ogg");
    music.Play(); /// só para testar
    

}

void State::Update(float dt){
    if (SDL_QuitRequested()){
        quitRequested = true;
    }
}

void State::Render(){
    bg.Render(0,-0);
}

bool State::QuitRequested() {
    return quitRequested;
}
