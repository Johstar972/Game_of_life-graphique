#include "../header/Game.hpp"
#include "../header/constants.hpp"
#include "../header/Menu.hpp"
#include "../header/GameBoard.hpp"
#include <iostream>

Game::Game()
{   
    window.create(sf::VideoMode(WIDTH_GAME, HEIGHT_GAME), "Game of life", sf::Style::Close);
    unsigned int screenSize_x = SCREEN[0].width / 8;
    unsigned int screenSize_y = SCREEN[0].height / 6;
    window.setPosition(sf::Vector2i(screenSize_x, screenSize_y));
    window.setFramerateLimit(TIME_PER_SECOND.asSeconds());
}

Game::~Game(){}

void Game::run()
{
    Menu menu;
    //Mettre une limite de colonne a 100
    GameBoard gameBoard(window, 75, 50);
    
    bool &inGame = _isRun; // Un indicateur pour savoir si le jeu est lancé
    sf::Clock clock;

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
                if(event.mouseButton.button == sf::Mouse::Left)
                {
                    //On récupère la position de la souris
                    int mouseX = sf::Mouse::getPosition(window).x;
                    int mouseY = sf::Mouse::getPosition(window).y;

                    if(inGame)
                    { 
                        gameBoard.cellIsClicked(mouseX, mouseY);
                        _isRun = gameBoard.buttonTextIsClicked(mouseX, mouseY, inGame, window);
                        
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
                else if( event.type == sf::Event::TextEntered)
                {
                    
                }
                
                
            }

        }

            
            clock.restart();
            window.clear();

            if (inGame)//Si je suis en jeu, je mets a jour l'affichage
            {
                //Si la grlle peut être modifier alors
                if(gameBoard.getIsChange())
                    //On appelle evolve pour passer à la prochaine génération de cellule
                    gameBoard.evolve(window);

                gameBoard.update(window);
                
            } 
            else //sinon j'affiche le menu
            {
                
                menu.draw(window);
                window.draw(menu.getGameTitle());
            }

            window.display();
    }
}

bool Game::getState() const
{
    return _isRun;
}