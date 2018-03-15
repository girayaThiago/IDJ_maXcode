//
//  State.h
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#ifndef State_h
#define State_h

#define INCLUDE_SDL

#include "Sprite.h"
#include "Music.h"
#include "SDL_include.h"

class State{
private:
    Sprite bg;
    Music music;
    bool quitRequested;

public:
    State();
    bool QuitRequested();
    void LoadAssets();
    void Update(float dt);
    void Render();
};

#endif /* State_h */
