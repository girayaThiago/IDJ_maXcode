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
#include "../include/Sprite.h"
#include "../include/Face.h"
#include "../include/Sound.h"
#include "../include/TileMap.h"
#include "../include/InputManager.h"

State::State() {
  quitRequested = false;
  music = Music();
  camera = Camera();
}

void State::LoadAssets() {
  GameObject *background = new GameObject();
  background->box.x = 0;
  background->box.y = 0;
  Sprite *bg = new Sprite(*background, "./assets/img/ocean.jpg");
  background->AddComponent(bg);
  objectArray.emplace_back(background);
  
  GameObject* tiles = new GameObject();
  tiles->box.x = 0;
  tiles->box.y = 0;
  TileSet* ts = new TileSet(*tiles, 64, 64, "./assets/img/tileset.png");
  TileMap* tm = new TileMap(*tiles, "./assets/map/tileMap.txt", ts);
  tiles->AddComponent(tm);
  objectArray.emplace_back(tiles);
  
  
    music.Open("./assets/audio/stageState.ogg");
    music.Play(); /// só para testar
}

State::~State(){
    objectArray.clear();
}

void State::Update(float dt){
  InputManager& manager = InputManager::GetInstance();
  if (manager.KeyPress(ESCAPE_KEY) || manager.QuitRequested()){
    quitRequested = true;
  }
  if (manager.KeyPress(SPACE_KEY)){
    Vec2 objPos = Vec2( 200, 0 ).GetRotated( -M_PI + M_PI*(rand() % 1001)/500.0 );
    AddObject(manager.GetMouseX() + objPos.x, manager.GetMouseY() + objPos.y);
  }
  if (manager.MousePress(LEFT_MOUSE_BUTTON)){
    int mouseX = manager.GetMouseX();
    int mouseY = manager.GetMouseY();
    for (int i = (int)objectArray.size()-1; i >= 0; i--){
      GameObject* go = (GameObject *)objectArray[i].get();
      if (go->box.Contains(mouseX, mouseY)){
        Face* face = (Face*)go->GetComponent("Face");
        if (face){
          face->Damage(std::rand() % 10 + 10);
          break;
        }
      }
    }
  }
  if (manager.KeyPress(LEFT_ARROW_KEY) || manager.KeyPress(RIGHT_ARROW_KEY)) {
    if (manager.KeyPress(LEFT_ARROW_KEY) && manager.KeyPress(RIGHT_ARROW_KEY)) {
      camera.speed.x = 0;
    } else if (manager.KeyPress(LEFT_ARROW_KEY)) {
      camera.speed.x = -10;
    } else { //RIGHT_ARROW_KEY
      camera.speed.x = 10;
    }
  }
  camera.Update(dt);
  for (int i = 0;  i < objectArray.size(); i++){
    objectArray[i]->Update(dt);
  }
   
  // TODO: desfazer esse cancer que tá esse update, tentar implementar um callback para o gameobject.
  for (int i = (int)objectArray.size()-1; i >= 0; i--){
    if (objectArray[i]->IsDead()){
      // esperar o som tocar antes de remover
      Sound* s = (Sound *) objectArray[i]->GetComponent("Sound");
      if (s) {
        if (!(s->IsPlaying())) {
          objectArray.erase(objectArray.begin()+i);
        }
      } else {
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
}

bool State::QuitRequested() {
    return quitRequested;
}
