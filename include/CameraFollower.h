//
//  CameraFollower.h
//  linkSDL
//
//  Created by Thiago Dantas on 19/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef CameraFollower_h
#define CameraFollower_h

#include "../include/Component.h"

class CameraFollower: public Component {
  CameraFollower(GameObject& go);
  void Update(float dt);
  void Render();
  bool Is(std::string type);
  
};

#endif /* CameraFollower_h */
