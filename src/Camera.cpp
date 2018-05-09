//
//  Camera.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 19/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Camera.h"
#include "../include/InputManager.h"

//Vec2 pos;
//Vec2 speed;

Vec2 Camera::pos = Vec2();
Vec2 Camera::speed = Vec2(100,100);
GameObject* Camera::focus = nullptr;
void Camera::NewFocus(GameObject* newFocus){
  focus = newFocus;
}
void Camera::Unfollow(){
  focus = nullptr;
}
void Camera::Update(float dt){
  if (focus != nullptr){
    //Se a câmera tiver um foco, faremos com que ele fique centralizado na tela;
    pos = focus->box.GetCenter();
  } else {
    InputManager& manager = InputManager::GetInstance();
    speed = Vec2();
    if (manager.IsKeyDown(LEFT_ARROW_KEY)) {
      Camera::pos.x += -Camera::speed.x * dt;
    }
    if (manager.IsKeyDown(RIGHT_ARROW_KEY)){
      Camera::pos.x += Camera::speed.x * dt;
    }
    if (manager.IsKeyDown(UP_ARROW_KEY)) {
      Camera::pos.y += -Camera::speed.y * dt;
    }
    if (manager.IsKeyDown(DOWN_ARROW_KEY)){
      Camera::pos.y += Camera::speed.y * dt;
    }
  }
}
