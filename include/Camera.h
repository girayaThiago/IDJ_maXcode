//
//  Camera.h
//  linkSDL
//
//  Created by Thiago Dantas on 19/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#ifndef Camera_h
#define Camera_h
#define INCLUDE_SDL

#include <stdio.h>
#include "../include/Component.h"
#include "../include/Vec2.h"
#include "../include/SDL_include.h"

class Camera{
public:
  static void NewFocus(GameObject* newFocus);
  static void Unfollow();
  static void Update(float dt);
  static Vec2 pos;
  static Vec2 speed;
private:
  static GameObject* focus;
};

#endif /* Camera_h */
