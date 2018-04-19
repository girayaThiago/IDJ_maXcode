//
//  Rect.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 17/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Rect.h"
#include <iostream>

Rect::Rect(){
    x = 0;
    y = 0;
    w = 0;
    h = 0;
}

Rect::Rect(float& x, float& y,
           float& w, float& h){
    this->x = x;
    this->y = y;
    this->w = w;
    this->h = h;
}

Vec2 Rect::GetCenter(){
    Vec2 center = Vec2();
    center.x = x + w/2;
    center.y = y + h/2;
    return center;
}

Rect& Rect::operator+(const Vec2& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}

Rect& Rect::operator-(const Vec2& rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}

Rect& Rect::operator=(const Vec2& rhs){
  this->x = rhs.x;
  this->y = rhs.y;
  return *this;
}

bool Rect::IsPointInside(Vec2& p){
    bool inside = true;
    if (p.x < x || p.x > x+w) inside = false;
    if (p.y < y || p.y > y+h) inside = false;
    return inside;
}

bool Rect::Contains(float px, float py){
    bool inside = true;
    if (px < x || px > x+w) inside = false;
    if (py < y || py > y+h) inside = false;
    return inside;
}
float Rect::DistanceTo(Rect& r){
    return (this->GetCenter() - r.GetCenter()).Magnitude();
}

