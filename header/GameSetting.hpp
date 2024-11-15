#ifndef GAMESETTING_HPP
#define GAMESETTING_HPP

#include <SFML/Graphics.hpp>
#include "Game.hpp"
                                                                                                                             
/**
 * @brief Class représentant l'interface des options de jeu
 * 
 */
class GameSetting 
{
private:
    float _width, _height;
    std::vector<sf::Text> _buttonSetting;
    std::vector<sf::RectangleShape> _shapes;
    std::vector<sf::Text> _texts;
    sf::Texture _texture;
    sf::Font _font;

public:
    /**
     * @brief Constructeur de la class GameSetting
     * 
     */
    GameSetting();

    /**
     * @brief Destructeur de class GameSetting
     * 
     */
    ~GameSetting();

    /**
     * @brief Fonction membre permettant de récupérer les formes rectangles
     * 
     * @return std::vector<sf::RectangleShape> 
     */
    std::vector<sf::RectangleShape> getShapes() const;

    /**
     * @brief Fonction membre permettant de récupérer les boutons textuels
     * 
     * @return std::vector<sf::Text>& 
     */
    const std::vector<sf::Text> &getButtonSetting() const;


    std::vector<sf::Text> &getText();
   
};

#endif  
