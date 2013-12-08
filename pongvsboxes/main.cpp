#include <SFML/Window.hpp>
#include <SFML/System.hpp>
#include <stdexcept>
#include <iostream>

#include "Game.h"
#include "Player.h"


int main(int argc, char *argv[])
{
    try{
    Game game;
    game.run();
    }
    catch (std::exception& e)
    {
        std::cout <<"\n Exception: " << e.what() << std::endl;
    }
    return 0;
}
