//
//  Music.h
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#ifndef Music_h
#define Music_h

#define INCLUDE_SDL
#define INCLUDE_SDL_MIXER

#include <iostream>
#include "SDL_include.h"

class Music{
private:
    Mix_Music* music;
public:
    Music();
    ~Music();
    Music(const char* file);
    void Play(int times = -1);
    void Stop(int msToStop = 1500);
    void Open(const char* file);
    bool IsOpen();
};


#endif /* Music_h */
