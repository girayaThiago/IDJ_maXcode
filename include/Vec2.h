//
//  Vec2.h
//  linkSDL
//
//  Created by Thiago Dantas on 17/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#pragma once

#ifndef Vec2_h
#define Vec2_h

#include <stdio.h>


class Vec2 {
public:
    float x;
    float y;
    Vec2();
    Vec2(float x, float y);
    Vec2& operator+(const Vec2& rhs);
    Vec2& operator-(const Vec2& rhs);
    Vec2& operator*(const float& rhs);
    Vec2& operator/(const float& rhs);
    friend Vec2 operator*(const float& lhs, Vec2& rhs);
    float Magnitude();
    Vec2 Normalized();
    float DistanceTo (Vec2 v);
    float Inclination();
    float InclinationWith (Vec2 v);
    Vec2 GetRotated(float angle);
};



#endif /* Vec2_h */
