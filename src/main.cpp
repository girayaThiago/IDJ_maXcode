//
//  main.cpp
//  IDJ_2018
//
//  Created by Thiago Dantas on 11/03/18.
//  Copyright © 2018 Thiago Dantas. All rights reserved.
//

#include <iostream>
#include "../include/Game.h"
//#include "Game.h"

int main(int argc, const char * argv[]) {
    std::cout << "main()\n";
    Game::GetInstance().Run();
    return 0;
}
