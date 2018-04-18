//
//  Camera.h
//  linkSDL
//
//  Created by Thiago Dantas on 19/04/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#ifndef Camera_h
#define Camera_h

#include <stdio.h>
#include "../include/Component.h"
#include "../include/Vec2.h"

class Camera{
public:
  void NewFocus(GameObject* newFocus);
  void Unfollow();
  void Update(float dt);
  Vec2 pos;
  Vec2 speed;
private:
  GameObject* focus;
};

#endif /* Camera_h */
