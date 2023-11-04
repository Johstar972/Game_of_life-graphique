#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/Game.hpp"

int main()
{
    //Activation de l'anticrenelage pour un rendu plus lisse sur les bords
    sf::ContextSettings settings;
    settings.antialiasingLevel = 8;

    Game game;

    game.run();

    /*
    TODO:Arranger les limite de ligne et de colonne pour l'utilisateur
    Ajouter le menu de controle a droite de l'ecran
    positionner le titre de les butons
    */

    

    return 0;
}
