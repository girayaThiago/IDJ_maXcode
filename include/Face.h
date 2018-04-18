//
//  Face.h
//  linkSDL
//
//  Created by Thiago Dantas on 31/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//
#pragma once

#ifndef Face_h
#define Face_h

#include <stdio.h>
#include "../include/Component.h"

class Face : public Component{
public:
    Face(GameObject& associated);
    
    void Damage(int damage);
    
    // Override Component
    void Update(float dt);
    void Render();
    bool Is(std::string type);
private:
    int hitpoints;
};

#endif /* Face_h */
