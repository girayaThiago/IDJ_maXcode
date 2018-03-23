//
//  GameObject.h
//  linkSDL
//
//  Created by Thiago Dantas on 19/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#pragma once

#ifndef GameObject_h
#define GameObject_h

#include <stdio.h>
#include <vector>
#include "../include/Component.h"
#include "../include/Rect.h"

class Component;

class GameObject{
public:
    GameObject();
    ~GameObject();
    
    Rect box;
    
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);
private:
    bool isDead;
    std::vector<Component*> components;
};


#endif /* GameObject_h */
