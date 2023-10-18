#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
private:
    float _width, _height;
    int buttonSelected;
    std::vector<sf::Text> buttonList;
    sf::Image gameTitle;
    sf::Font font;

public:
    Menu();
    void draw(sf::RenderWindow &window);

    ~Menu();
};
