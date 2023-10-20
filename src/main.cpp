#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/menu.hpp"
#include "../header/constants.hpp"

int main()
{
    sf::RenderWindow window;
    window.create(sf::VideoMode(1000,1000),"Game of life",sf::Style::Default);
    unsigned int screenSize_x = SCREEN[0].width / 3; unsigned int screenSize_y = SCREEN[0].height / 6;
    window.setPosition(sf::Vector2i(screenSize_x, screenSize_y));
    

    Menu menu;

    sf::Text buttonPlay = menu.getButtonList()[0];
    sf::Text buttonQuit = menu.getButtonList()[1];
    sf::Sprite gameTitleSprite = menu.getGameTitle();
    

    
    while(window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch (event.type)
            {
            case sf::Event::Closed:
                window.close();
                break;

            case sf::Event::MouseButtonPressed:
                int mouseX = sf::Mouse::getPosition(window).x;
                int mouseY = sf::Mouse::getPosition(window).y;


                sf::FloatRect buttonQuitBounds = buttonQuit.getGlobalBounds();
                sf::FloatRect buttonPlayBounds = buttonPlay.getGlobalBounds();
                if(buttonPlayBounds.contains(mouseX, mouseY))
                {
                    std::cout << "is the boutton play !" << std::endl;
                    window.close();
                }
                else if(buttonQuitBounds.contains(mouseX, mouseY))
                {
                    std::cout << "is the boutton quit !" << std::endl;
                }
                break;

            }
            
        }
        window.clear();
        menu.draw(window);
        window.draw(menu.getGameTitle());
        window.display();
        
    }
    
    return 0;
}