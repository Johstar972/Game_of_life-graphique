#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Game.hpp"
#include "../header/Cell.hpp"

int main()
{
    //Activation de l'anticrenelage pour un rendu plus lisse sur les bords
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Game game;
    game.run();

    return 0;
}
