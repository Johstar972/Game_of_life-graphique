#include "../header/Game.hpp"
#include "../header/constants.hpp"
#include "../header/Menu.hpp"
#include "../header/Grid.hpp"

Game::Game()
{
    window.create(sf::VideoMode(2000, 1000), "Game of life", sf::Style::Close);
    unsigned int screenSize_x = SCREEN[0].width / 8;
    unsigned int screenSize_y = SCREEN[0].height / 6;
    window.setPosition(sf::Vector2i(screenSize_x, screenSize_y));
}

Game::~Game()
{
}

void Game::run()
{
    Menu menu;
    //Mettre une limite de colonne a 100
    Grid grid(window, 20, 25);
    //TODO:Enlever le booleen pour l'etat du jouer car ecrit hello en boucle
    bool inGame = false; // Un indicateur pour savoir si nous sommes dans le jeu
    bool initGame = false;

    //grid.draw(window, 10, 10);

    while (window.isOpen())
    {
        sf::Event event;
        
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed)//Si c'est un event de fermeture
            {
                window.close();// On ferme la fenêtre
            }
            else if(event.type == sf::Event::MouseButtonPressed)//Si c'est un event où l'on clic sur un bouton de la souris
            {
                //On récupère la position de la souris
                int mouseX = sf::Mouse::getPosition(window).x;
                int mouseY = sf::Mouse::getPosition(window).y;

                if(inGame)
                {
                    grid.update(window); 
                    std::cout << "je clique pendant que le jeu est activer" << std::endl;
                    grid.cellIsClicked(mouseX, mouseY);
                    
                }
                else
                {
                    //On stock les bouton du menu dans des variables
                sf::Text buttonPlay = menu.getButtonList()[0];
                sf::Text buttonQuit = menu.getButtonList()[1];
                sf::Sprite gameTitleSprite = menu.getGameTitle();

                //On récupère le nuage de point des boutons du menu
                sf::FloatRect buttonQuitBounds = buttonQuit.getGlobalBounds();
                sf::FloatRect buttonPlayBounds = buttonPlay.getGlobalBounds();
            
                //Si la souris clique sur l'un des points contenue dans le bouton play du menu
                if (buttonPlayBounds.contains(mouseX, mouseY))
                {
                    std::cout << "C'est le bouton play !" << std::endl;
                    inGame = true; // Passer à l'état de jeu
                }
                else if (buttonQuitBounds.contains(mouseX, mouseY))//Sinon si la souris clique sur l'un des points contenue dans le bouton quit
                {
                    std::cout << "C'est le bouton quit !" << std::endl;
                    window.close();//On ferme la fenetre
                }
                }
                
            }

            window.clear();

            if (inGame)
            {

                grid.update(window);
                
            } else {
                // Affichez le menu
                menu.draw(window);
                window.draw(menu.getGameTitle());
            }

            window.display();
        }
    }
}