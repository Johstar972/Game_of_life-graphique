#ifndef POSITION_H
#define POSITION_H

#include <iostream>
/**
 * Cette classe représente une position  avec un x et un y
 */
class Position
{

private:
    int _x, _y;
public:

    /**
     * Constructeur par défaut
     */
    Position();

    /**
     * Constructeur par copie
     * @param position la position à copié
     */
    Position(const Position &position);


    /**
     * Constructeur par paramètre ( x,y )
     * @param x le 1er point de la position
     * @param y le 2ème point de la position
     */
    Position(int x, int y);

    /**
     * Méthode permettant de récupérer la valeur de x sur une Position
     * @return la valeur de x
     */
    int getX() const;

    /**
     * Méthode permettant de modifié la valeur de x d'une Position
     * @param newX la nouvelle valeur de x
     */
    inline void setX(int newX);

    /**
     * Méthode permettant de récupérer la valeur de y sur une Position
     * @return la valeur de y
     */
    int getY() const;

    /**
     * Méthode permettant de modifié la valeur de y d'une Position
     * @param newY la nouvelle valeur de y
     */
    inline void setY(int newY);

    /**
     * Methode permettant d'afficher une position
     * @param os flux sortant
     * @param position l'objet à afficher
     * @return retour une chaine de caractère de l'objet
     */
    friend std::ostream& operator<<(std::ostream& os, Position& position);

    bool operator==(const Position &position) const;
};

inline std::ostream& operator<<(std::ostream& os, Position& position)
{
    os << "X : "<< position._x <<", Y : "<< position._y << std::endl;

     return os;
}

inline void Position::setX(int newX)
{

    this -> _x = newX;
}

inline void Position::setY(int newY)
{
    this -> _y = newY;
}

#endif