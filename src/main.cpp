#include <iostream>
#include <SFML/Graphics.hpp>
#include "../header/menu.hpp"

int main()
{
    sf::RenderWindow windowMenu(sf::VideoMode(800,800),"Game of life",sf::Style::Default);
    Menu menu;

    while(windowMenu.isOpen())
    {
        sf::Event event;
        while (windowMenu.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                windowMenu.close();
            }
        }
        windowMenu.clear();
        menu.draw(windowMenu);
        windowMenu.display();
        
    }
    
    return 0;
}