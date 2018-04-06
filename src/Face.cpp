//
//  Face.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 31/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Sound.h"
#include "../include/Face.h"

Face::Face(GameObject& associated): Component(associated){
    hitpoints = 30;
    printf("Face intanciada! HP = %d\n", hitpoints);
}

void Face::Damage(int damage){
    hitpoints -= damage;
//    hitpoints = 0;
    printf("apanhou! vida restante: %d\n", hitpoints);
    if (hitpoints <= 0){
        associated.RequestDelete();
//        ((Sound*) associated.GetComponent("Sound"))->Play();
        Sound* s = (Sound*) associated.GetComponent("Sound");
        if (s) s->Play();
        
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
