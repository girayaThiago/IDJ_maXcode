//
//  Component.cpp
//  linkSDL
//
//  Created by Thiago Dantas on 20/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include "../include/Component.h"

Component::Component(GameObject& associated): associated(associated){}
Component::~Component(){}
