//
//  Geometry.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 17/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//


#include <cmath>
#include "../include/Vec2.h"

Vec2::Vec2(){
    x = 0;
    y = 0;
}

Vec2::Vec2(float x, float y){
    this->x = x;
    this->y = y;
}


Vec2& Vec2::operator+(const Vec2& rhs){
    this->x += rhs.x;
    this->y += rhs.y;
    return *this;
}
Vec2& Vec2::operator-(const Vec2& rhs){
    this->x -= rhs.x;
    this->y -= rhs.y;
    return *this;
}
Vec2& Vec2::operator*(const float& rhs){
    this->x *= rhs;
    this->y *= rhs;
    return *this;
}
Vec2& operator*(float& lhs, Vec2& rhs){
    return rhs * lhs;
}
Vec2& Vec2::operator/(const float& rhs){
    this->x /= rhs;
    this->y /= rhs;
    return *this;
}

/// Brief: O modulo do vetor;
float Vec2::Magnitude(){
    return hypot(x, y);
}
/// Brief: Um versor (vetor unitário) com mesma orientação que o vetor (direção e sentido);
Vec2 Vec2::Normalized(){
    return *this/Magnitude();
}

/// Brief: O modulo da distancia entre os 2 vetores;
float Vec2::DistanceTo (Vec2 v){
    return (v - *this).Magnitude();
}

float Vec2::Inclination(){
    // usando arco cosseno do cosseno = angulo, cos = cateto adjacente (componente em X) / hiptenusa (modulo);
    return acos(cos(x/ this->Magnitude()));
}

/// TODO
float Vec2::InclinationWith (Vec2 v){
    return 1.0;
}

/// TODO
Vec2 Vec2::Rotate(float angle){
    // M_PI rad = 180º
    // 1 rad = 180 / M_PI
    // float rad = 180 / M_PI;
    return Vec2();
}
