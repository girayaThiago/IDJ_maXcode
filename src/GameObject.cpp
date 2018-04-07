//
//  GameObject.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 19/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/GameObject.h"

GameObject::GameObject(){
    isDead = false;
}

GameObject::~GameObject(){
    components.clear();
}

void GameObject::Update(float dt){
    for (int i = 0; i < components.size(); i++){
        components[i]->Update(dt);
    }
}

void GameObject::Render(){
    for (int i = 0; i < components.size(); i++){
        components[i]->Render();
    }
}

bool GameObject::IsDead(){
    return isDead;
}

void GameObject::RequestDelete(){
    isDead = true;
}

void GameObject::AddComponent(Component* cpt){
    components.emplace_back(cpt);
}

void GameObject::RemoveComponent(Component* cpt){
    for (int  i = 0; i < components.size(); i++){
        if (components[i].get() == cpt) {
            components.erase(components.begin()+i);
            break;
        }
    }
}

Component* GameObject::GetComponent(std::string type){
    for (int i = 0; i < components.size(); i++){
        if (components[i]->Is(type)) {
            return components[i].get();
        }
    }
    return nullptr;
}
