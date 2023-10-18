#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
private:
    float _width, _height;
    int _buttonSelected;
    std::vector<sf::Text> _buttonList;
    sf::Sprite _gameTitle;
    sf::Font _font;

public:
    Menu(const sf::Texture &textureTitle);
    void draw(sf::RenderWindow &window);
    std::vector<sf::Text> getButtonList() const;
    sf::Sprite getGameTitle() const;

    ~Menu();
};
