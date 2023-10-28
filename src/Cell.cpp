#include "../header/Cell.hpp"
#include "../header/Position.hpp"
#include <iostream>
#include <stdexcept>

Cell::Cell()
{
    this->_alive = 0; //Par défaut une cellule est morte
    this->_position = Position();
    this->_shape.setSize(sf::Vector2f(10,10));
    
}

Cell::Cell(const Cell &cell)
{
    this->_alive = cell._alive;
    this->_position = cell._position;
    this->_shape = cell._shape;
    
}

Cell::Cell(int alive, const Position &position, const sf::RectangleShape &shape)
{
    this->_alive = alive;
    this->_position = position;
    this->_shape = shape;
}

Cell::~Cell()
{
}


int Cell::getAlive() const
{
    return this->_alive;
}

Position Cell::getPosition() const
{
    return this->_position;
}

sf::RectangleShape &Cell::getShape()
{
    return this->_shape;
}

sf::FloatRect Cell::getRectBounds() const
{
    return this->_bounds;
}

void Cell::setRectBounds(sf::FloatRect fr)
{
    this->_bounds = fr;
}
// bool Cell::operator==(const Cell &cell) const
// {
//     return(_alive == cell._alive && _position.operator==(cell._position));
// }

// bool Cell::operator!=(const Cell &cell)
// {
//     return !(this->operator==(cell));
// }