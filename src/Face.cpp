//
//  Face.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 31/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Sound.h"
#include "../include/Face.h"
#include "../include/Sprite.h"

Face::Face(GameObject& associated): Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
    if (hitpoints <= 0 && !associated.IsDead()){
        Sound* s = (Sound*) associated.GetComponent("Sound");
        if (s) s->Play();
        associated.RequestDelete();
        
        // Remover componentes que fazem o inimigo apanhar e ser visto, update aguarda o som parar de tocar.
        Sprite* spr = (Sprite *) associated.GetComponent("Sprite");
        if (spr) associated.RemoveComponent(spr);
        associated.RemoveComponent(this);
    }
}

// Override Component
void Face::Update(float dt){
}
void Face::Render(){
}
bool Face::Is(std::string type){
    return type.compare("Face") == 0 ? true : false;
}
