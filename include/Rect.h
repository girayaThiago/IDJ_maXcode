//
//  Rect.h
//  linkSDL
//
//  Created by Thiago Dantas on 17/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#pragma once

#ifndef Rect_h
#define Rect_h

#include <stdio.h>
#include "Vec2.h"

class Rect {
public:
  float x;
  float y;
  float w;
  float h;
  Rect();
  Rect(float& x, float& y,
       float& w, float& h);
  Vec2 GetCenter();
  Rect& operator+(const Vec2& rhs);
  Rect& operator-(const Vec2& rhs);
  Rect& operator=(const Vec2& rhs);
  bool IsPointInside(Vec2& p);
  bool Contains(float px, float py);
  float DistanceTo(Rect& r);
    
};

#endif /* Rect_h */
