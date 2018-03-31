//
//  Face.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 31/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Face.h"

Face::Face(GameObject& associated): Component(associated){
    hitpoints = 30;
}

void Face::Damage(int damage){
    hitpoints -= damage;
}

// Override Component
void Face::Update(float dt){
    
}
void Face::Render(){
    
}
bool Face::Is(std::string type){
    return type.compare("Face") == 0 ? true : false;
}
