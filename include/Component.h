//
//  Component.h
//  linkSDL
//
//  Created by Thiago Dantas on 20/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#pragma once

#ifndef Component_h
#define Component_h

#include <stdio.h>
#include <string>
#include "../include/GameObject.h"

class GameObject;

class Component{
public:
    Component(GameObject& associated);
    ~Component();
    void virtual Update(float dt);
    void virtual Render();
    bool virtual Is(std::string type);
protected:
    GameObject& associated;
};


#endif /* Component_h */
