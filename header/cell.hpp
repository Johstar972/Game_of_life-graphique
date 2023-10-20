#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "position.hpp"
#include <SFML/Graphics.hpp>

class Cell
{
private:
    int _alive;
    sf::RectangleShape _shape;
    Position _position;

public:
    /**
     * @brief Constructeur par défaut
     *
     */
    Cell();

    /**
     * @brief Constructeur par copie
     *
     * @param cell la cellule que l'on souhaite copier
     */
    Cell(const Cell &cell);

    /**
     * @brief Constructeur par paramètre
     *
     * @param alive L'état de la vie de la cellule
     * @param position La position de la cellule
     */
    Cell(int alive, const Position &position, const sf::RectangleShape &shape);

    /**
     * @brief Destructeur de la class Cell
     *
     */
    ~Cell();

    /**
     * @brief Méthode permettant de récupérer l'état de vie de la cellule
     *
     * @return int
     */
    int getAlive() const;

    /**
     * @brief Méthode permettant de récupérer la position de la cellule
     *
     * @return Position
     */
    Position getPosition() const;

    sf::RectangleShape getShape() const;

    /**
     * @brief Méthode permettant de modifier la position d'une cellule
     *
     * @param newX La position x de la cellule
     * @param newY La position y de la cellule
     */
    inline void setPosition(int newX, int newY);

    /**
     * @brief Méthode permettant de modifier l'état de vie de la cellule
     *
     * @param alive Le nouvelle état de vie de la cellule
     */
    inline void setAlive(int alive);

    /**
     * @brief Méthode permettant de redéfinir l'opérateur de flux <<
     * pour afficher de manière personalisée une cellule
     *
     * @param os L'opérateur de sortie
     * @param cell La cellule
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);
};

inline std::ostream &operator<<(std::ostream &os, const Cell &cell)
{
    if(cell._alive == 0)
    {
        os << "Cellule morte en :" << "(" << cell._position.getX() <<"," << cell._position.getY() << ")" << std::endl;

    }
    else
    {
        os << "Cellule vivante: " << "(" << cell._position.getX() <<"," << cell._position.getY() << ")" << std::endl;

    }

    return os;
}

inline void Cell::setAlive(int alive)
{

        if(this->_alive == 0 && alive == 1 || alive == 0)
        {
            this->_alive = alive;
        }
        else if(this->_alive == 1 && alive == 0 || alive == 1)
        {
            this->_alive = alive;
        }
        else
        {
            throw std::invalid_argument("Une cellule vivant (1) peut être morte (0) ou inversement");
        }

}

inline void Cell::setPosition(int newX, int newY)
{
    this->_position.setX(newX);
    this->_position.setY(newY);
}
#endif