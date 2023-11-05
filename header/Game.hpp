#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics/RenderWindow.hpp>
#include <iostream>

class Game
{
private:
    sf::RenderWindow window;
    const sf::Time TIME_PER_SECOND = sf::seconds(5.f);
    bool _isRun = false;
    
public:
    /**
     * @brief Constructeur de la class Game
     * 
     */
    Game();

    /**
     * @brief Destructeur de la class Game
     * 
     */
    ~Game();

    /**
     * @brief Fonction membre permettant de lancer le jeu
     * 
     */
    void run();

    /**
     * @brief Fonction membre permettant de récupérer l'état du jeu
     * 
     * @return true Si le jeu est lancé,
     * @return sinon false 
     */
    bool getState() const;

    /**
     * @brief Fonction membre permettant de changer l'état du jeu
     * 
     * @param newState 
     */
    void setState(bool newState);
};

inline void Game::setState(bool newState)
{
    if(!_isRun && newState)
    {
        _isRun = newState;
    }
    else if(_isRun && !newState)
    {
        _isRun = newState;
    }
    else
    {
        std::cerr << "Vous ne pouvez pas donner à l'état du jeu la même valeur" << std::endl;
    }
}

#endif