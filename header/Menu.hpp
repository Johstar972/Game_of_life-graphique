#include <SFML/Graphics.hpp>
#include <iostream>

class Menu
{
private:
    float _width, _height;
    int _buttonSelected;
    
    std::vector<sf::Text> _buttonList;
    sf::Texture _gameTitleTexture;
    sf::Sprite _gameTitleSprite;
    sf::Font _font;

public:
    /**
     * @brief Construct a new Menu object
     * 
     */
    Menu();

    /**
     * @brief 
     * 
     * @param window 
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Get the Button List object
     * 
     * @return std::vector<sf::Text> 
     */
    std::vector<sf::Text> getButtonList() const;

    /**
     * @brief Get the Game Title object
     * 
     * @return sf::Sprite 
     */
    sf::Sprite getGameTitle() const;


    ~Menu();
};
