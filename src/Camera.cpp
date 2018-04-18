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
    // Se não houver um foco, devemos responder ao input: Setamos a velocidade da câmera de acordo com dt e com as teclas pressionadas, e somamos à posição.
    pos.x += speed.x * dt;
    pos.y += speed.y * dt;
    // Speed é setado de acordo com o input durante o main game loop ao apertar as telcas LEFT e RIGHT _KEY
  }
}
