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
//    while (components.size()){
//        Component* c = components[components.size()-1].get();
//        components.erase(components.begin()+components.size()-1);
//        delete c;
//    }
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
    components.erase(find(components.begin(), components.end(), cpt));
}

Component* GameObject::GetComponent(std::string type){
    Component* c = nullptr;
    for (int i = 0; i < components.size() && c == nullptr; i++){
        if (components[i]->Is(type)) {
            c = components[i].get();
        }
    }
    return c;
}
