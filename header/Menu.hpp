#include <SFML/Graphics.hpp>
#include <iostream>

/**
 * @brief Class représentant le menu du jeu
 * 
 */
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
     * @brief Constructeur par défaut de la class Menu
     * 
     */
    Menu();

    /**
     * @brief Méthide permettant de dessiner le menu
     * 
     * @param window La fenêtre
     */
    void draw(sf::RenderWindow &window);

    /**
     * @brief Méthode permettant de récupérer la liste des boutons
     * 
     * @return std::vector<sf::Text> La liste des boutons
     */
    std::vector<sf::Text> getButtonList() const;

    /**
     * @brief Méthode permettant de récupérer le sprite du titre du jeu
     * 
     * @return sf::Sprite 
     */
    sf::Sprite getGameTitle() const;

    /**
     * @brief Destructeur de la class Menu
     * 
     */
    ~Menu();
};
