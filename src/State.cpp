//
//  State.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include <memory>
#include <iostream>

#include "../include/Game.h"
#include "../include/State.h"
#include "../include/Face.h"
#include "../include/Sound.h"

State::State() {
    quitRequested = false;
    music = Music();
}

void State::LoadAssets() {
    GameObject *background = new GameObject();
    background->box.x = 0;
    background->box.y = 0;
    Sprite *bg = new Sprite(*background, "./assets/img/ocean.jpg");
    background->AddComponent(bg);
    objectArray.emplace_back(background);

    music.Open("./assets/audio/stageState.ogg");
    music.Play(); /// só para testar

}

State::~State(){
    objectArray.clear();
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
            for(int i = (int)objectArray.size()-1; i >= 0; i--) {
                // Obtem o ponteiro e casta pra Face.
                GameObject* go = (GameObject*) objectArray[i].get();
                // Nota: Desencapsular o ponteiro é algo que devemos evitar ao máximo.
                // O propósito do unique_ptr é manter apenas uma cópia daquele ponteiro,
                // ao usar get(), violamos esse princípio e estamos menos seguros.
                // Esse código, assim como a classe Face, é provisório. Futuramente, para
                // chamar funções de GameObjects, use objectArray[i]->função() direto.
//                std::cout << "box " << i << ":\n\tx: " << go->box.x << " y: " << go->box.y << "\n\tw: " << go->box.w << " h: " << go->box.h << std::endl;
                if(go->box.Contains( mouseX, mouseY) ) {
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
    
    for (int i = 0;  i < objectArray.size(); i++){
        objectArray[i]->Update(dt);
    }
    // TODO: desfazer esse cancer que tá esse update
    for (int i = (int)objectArray.size()-1; i >= 0; i--){
        if (objectArray[i]->IsDead()){
            // Se um objeto tem de morrer, remova os componentes de face e sprite
            Face* f = (Face *) objectArray[i]->GetComponent("Face");
            if (f) objectArray[i]->RemoveComponent(f);
            
            Sprite* spr = (Sprite *) objectArray[i]->GetComponent("Sprite");
            if (spr) objectArray[i]->RemoveComponent(spr);
            
            // esperar o som tocar antes de remover
            Sound* s = (Sound *) objectArray[i]->GetComponent("Sound");
            if (s) if (!(s->IsPlaying())){
                objectArray.erase(objectArray.begin()+i);
            }
        }
    }
}

void State::Render(){
    for (int i = 0; i < objectArray.size(); i++){
        objectArray[i]->Render();
    }
}

void State::AddObject(int mouseX, int mouseY){
    GameObject* obj = new GameObject();
    Sprite* pengimg = new Sprite(*obj, "./assets/img/penguinface.png");
    obj->box.x = mouseX - obj->box.w/2;
    obj->box.y = mouseY - obj->box.h/2;
    obj->AddComponent(pengimg);
    
    Sound* pengsound = new Sound(*obj, "./assets/audio/boom.wav");
    obj->AddComponent(pengsound);
    
    Face* pengface = new Face(*obj);
    obj->AddComponent(pengface);
    
    
    objectArray.emplace_back(obj);
//    pengface->Damage(0);
    
    
}

bool State::QuitRequested() {
    return quitRequested;
}
