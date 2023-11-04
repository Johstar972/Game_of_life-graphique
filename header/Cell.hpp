#ifndef CELL_H
#define CELL_H
#include <iostream>
#include "Position.hpp"
#include <SFML/Graphics.hpp>

class Cell
{
private:
    int _alive;
    sf::RectangleShape _shape;
    float _rectSize;
    int currentCellSize;
    sf::FloatRect _bounds;
    Position _position;

public:
    /**
     * @brief Constructeur par défaut de la class Cell
     *
     */
    Cell();

    /**
     * @brief Constructeur par copie de la class Cell
     *
     * @param cell la cellule que l'on souhaite copier
     */
    Cell(const Cell &cell);

    /**
     * @brief Constructeur par paramètre de la class Cell
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
     * @brief Fonction membre permettant de récupérer l'état de vie de la cellule
     *
     * @return int
     */
    int getAlive() const;

    /**
     * @brief Fonction membre permettant de récupérer la position de la cellule
     *
     * @return Position
     */
    Position getPosition() const;

    /**
     * @brief Fonction membre permettant de récupérer la forme de la cellule
     * 
     * @return sf::RectangleShape& 
     */
    sf::RectangleShape &getShape();

    /**
     * @brief Fonction membre permetttant de recupérer le nuage de point du shape
     * 
     * @return sf::FloatRect 
     */
    sf::FloatRect getRectBounds() const;

    /**
     * @brief Fonction membre permettant de modifier le nuage de point du shape
     * 
     * @param fr 
     */
    void setRectBounds(sf::FloatRect fr);

    /**
     * @brief Fonction membre permettant de changer l'indicateur de taille de la cellule
     * 
     * @param newSizeId 
     */
    void setCurrentCellSize(int newSizeId);

    /**
     * @brief Fonction membre permettant de modifier la position d'une cellule
     *
     * @param newX La position x de la cellule
     * @param newY La position y de la cellule
     */
    void setPosition(int newX, int newY);

    /**
     * @brief Fonction membre permettant de modifier l'état de vie de la cellule
     *
     * @param alive Le nouvelle état de vie de la cellule
     */
    void setAlive(int alive);

    /**
     * @brief Fonction membre permettant de récupérer la taille de la forme d'une cellule
     * 
     * @return float& 
     */
    float &getRectSize();

    /**
     * @brief Fonction membre permettant de redéfinir l'opérateur de flux <<
     * pour afficher de manière personalisée une cellule
     *
     * @param os L'opérateur de sortie
     * @param cell La cellule
     * @return std::ostream&
     */
    friend std::ostream &operator<<(std::ostream &os, const Cell &cell);

    /**
     * @brief Fonction membre permettant de redéfinir l'opérateur ==
     * pour comparer deux cellules
     * 
     * @param cell La cellule que l'on souhaite comparer
     * @return true s'il y a égalité
     * @return sinon false 
     */
    bool operator==(const Cell &cell) const;

    /**
     * @brief Fonction membre permettant de rédéfinir l'opérateur !=
     * pour comparer deux cellules
     * 
     * @param cell La cellule que l'on souhaite comparé
     * @return true s'il y a inégalié
     * @return sinon false 
     */
    bool operator!=(const Cell &cell);
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

        if(this->_alive == 0 && alive == 1)
        {
            this->_alive = alive;
            _shape.setFillColor(sf::Color(255,255,0));
        }
        else if(this->_alive == 1 && alive == 0)
        {
            this->_alive = alive;
            _shape.setFillColor(sf::Color::Black);
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

inline void Cell::setCurrentCellSize(int newCellSizeId)
{
    if(newCellSizeId >= 0 || newCellSizeId <= 8)
        this->_rectSize = newCellSizeId;
    else
        std::__throw_invalid_argument("L'indicateur de taille de la cellule ne peut pas être sup a 8 ou inf a 0");
}


#endif