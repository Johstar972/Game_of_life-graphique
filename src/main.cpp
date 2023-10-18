#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/menu.hpp"

int main()
{
    sf::RenderWindow windowMenu(sf::VideoMode(800,800),"Game of life",sf::Style::Default);
    
    sf::Texture gameTitleTexture;
    if(!gameTitleTexture.loadFromFile(("../image_fonts/main_menu_title.png")))
        std::perror("picture not found");

    Menu menu(gameTitleTexture);

    sf::Text buttonPlay = menu.getButtonList()[0];
    sf::Text buttonQuit = menu.getButtonList()[1];
    sf::Sprite gameTitleSprite = menu.getGameTitle();
    

    
    while(windowMenu.isOpen())
    {
        sf::Event event;
        while (windowMenu.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                windowMenu.close();
                break;

            case sf::Event::MouseButtonPressed:
                int mouseX = sf::Mouse::getPosition(windowMenu).x;
                int mouseY = sf::Mouse::getPosition(windowMenu).y;


                sf::FloatRect buttonQuitBounds = buttonQuit.getGlobalBounds();
                sf::FloatRect buttonPlayBounds = buttonPlay.getGlobalBounds();
                if(buttonPlayBounds.contains(mouseX, mouseY))
                {
                    std::cout << "is the boutton play !" << std::endl;
                }
                else if(buttonQuitBounds.contains(mouseX, mouseY))
                {
                    std::cout << "is the boutton quit !" << std::endl;
                }
                break;

            }
            
        }
        windowMenu.clear();
        menu.draw(windowMenu);
        windowMenu.draw(gameTitleSprite);
        windowMenu.display();
        
    }
    
    return 0;
}