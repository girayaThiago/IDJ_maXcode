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

#include <memory>
#include <stdio.h>
#include <vector>
#include "../include/Component.h"
#include "../include/Rect.h"

class Component;

class GameObject{
public:
    GameObject();
    ~GameObject();
    
    void Update(float dt);
    void Render();
    bool IsDead();
    void RequestDelete();
    void AddComponent(Component* cpt);
    void RemoveComponent(Component* cpt);
    Component* GetComponent(std::string type);
    
    Rect box;
private:
    std::vector<std::unique_ptr<Component>> components;
    bool isDead;
};


#endif /* GameObject_h */
