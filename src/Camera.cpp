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
Vec2 Camera::speed = Vec2();
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
    // Se não houver um foco, devemos responder ao input: Setamos a velocidade da câmera de acordo com dt e com as teclas pressionadas, e somamos à posição.
//    if (speed.x != 0) {
//      printf("Camera deveria estar se movendo\n");
//    }
    pos.x += (speed.x + speed.y) * dt; //utilizando x e y como controle para movimento na horizontal;
//    pos.x += speed.x * dt;
//    pos.y += speed.y * dt;
    // Speed é setado de acordo com o input durante o main game loop ao apertar as telcas LEFT e RIGHT _KEY
  }
}
