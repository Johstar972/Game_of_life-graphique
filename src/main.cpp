#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Game.hpp"

int main()
{
    //Activation de l'anticrenelage pour un rendur plus lisse sur les bords
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Game game;

    game.run();


    

    return 0;
}
