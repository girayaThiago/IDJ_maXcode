//
//  State.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include <iostream>

#include "../include/Game.h"
#include "../include/State.h"
#include "../include/Face.h"
#include "../include/Sound.h"



State::State() {
    quitRequested = false;
//    std::cout << "State initialized" << std::endl;
    objects.emplace_back(new GameObject());
    GameObject g = GameObject();
    bg = Sprite(g, "./assets/img/penguin.png");
    objects[0]->AddComponent(&bg);
    
    
    music = Music();

}

void State::LoadAssets() {
//    printf("LoadAssets()\n");
//    bg.Open("./assets/img/ocean.jpg");
//    music.Open("./assets/audio/stageState.ogg");
//    music.Play(); /// só para testar
    

}

State::~State(){
    objects.clear();
    
}

void State::Input(){
    SDL_Event event;
    int mouseX, mouseY;
    
    // Obtenha as coordenadas do mouse
    SDL_GetMouseState(&mouseX, &mouseY);
    
    // SDL_PollEvent retorna 1 se encontrar eventos, zero caso contrário
    while (SDL_PollEvent(&event)) {
        
        // Se o evento for quit, setar a flag para terminação
        if(event.type == SDL_QUIT) {
            quitRequested = true;
        }
        
        // Se o evento for clique...
        if(event.type == SDL_MOUSEBUTTONDOWN) {
            
            // Percorrer de trás pra frente pra sempre clicar no objeto mais de cima
            for(int i = objects.size() - 1; i >= 0; --i) {
                // Obtem o ponteiro e casta pra Face.
                GameObject* go = (GameObject*) objects[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.
                
                if(go->box.Contains( (float)mouseX, (float)mouseY) ) {
                    Face* face = (Face*)go->GetComponent( "Face" );
                    if ( nullptr != face ) {
                        // Aplica dano
                        face->Damage(std::rand() % 10 + 10);
                        // Sai do loop (só queremos acertar um)
                        break;
                    }
                }
            }
        }
        if( event.type == SDL_KEYDOWN ) {
            // Se a tecla for ESC, setar a flag de quit
            if( event.key.keysym.sym == SDLK_ESCAPE ) {
                quitRequested = true;
            }
            // Se não, crie um objeto
            else {
                Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 ) + Vec2( mouseX, mouseY );
                AddObject((int)objPos.x, (int)objPos.y);
            }
        }
    }
}

void State::Update(float dt){
    Input();
    
    for (int i = 0;  i < objects.size(); i++){
        objects[i].get()->Update(dt);
    }
    
    for (int i = (int)objects.size(); i >= 0; i--){
        if (objects[i]->IsDead()) objects.erase(objects.begin()+i);
    }
}

void State::Render(){
//    bg.Render(0,-0);
    for (int i = 0; i < objects.size(); i++){
        objects[i]->Render();
    }
}

void State::AddObject(int mouseX, int mouseY){
    std::unique_ptr<GameObject> obj(new GameObject());
    Sprite* pengimg = new Sprite(*obj, "./assets/img/penguin.png");
    Sound* pengsound = new Sound(*obj, "./assets/audio/boom.wav");
    Face* pengface = new Face(*obj);
    obj->AddComponent(pengimg);
    obj->AddComponent(pengsound);
    obj->AddComponent(pengface);
    objects.emplace_back(obj);
}

bool State::QuitRequested() {
    return quitRequested;
}
