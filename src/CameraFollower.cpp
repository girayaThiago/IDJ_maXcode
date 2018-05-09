//
//  CameraFollower.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 19/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/CameraFollower.h"
#include "../include/Camera.h"

CameraFollower::CameraFollower(GameObject& go) : Component(go){
  
}
void CameraFollower::Update(float dt){
  associated.box = Camera::pos;
}
void CameraFollower::Render(){
  
}
bool CameraFollower::Is(std::string type){
  return (type.compare("CameraFollower") == 0) ? true : false;
}

