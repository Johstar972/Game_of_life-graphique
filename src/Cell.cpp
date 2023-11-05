#include "../header/Cell.hpp"
#include "../header/Position.hpp"
#include "../header/constants.hpp"
#include <iostream>
#include <stdexcept>

Cell::Cell()
{
    this->_alive = 0; //Par défaut une cellule est morte
    this->_position = Position();
    this->_shape.setSize(sf::Vector2f(10,10));
    this->_currentCellSize = 1;
    this->_rectSize = SIZES[_currentCellSize];
    this->_bounds = _shape.getGlobalBounds();
}

Cell::Cell(const Cell &cell)
{
    this->_alive = cell._alive;
    this->_position = cell._position;
    this->_shape = cell._shape;
    this->_currentCellSize = cell._currentCellSize;
    this->_rectSize = cell._rectSize;
    this->_bounds = cell._bounds;
}

Cell::~Cell(){}

void Cell::initShape(int row, int col )
{

    this->_shape.setSize(sf::Vector2f(_rectSize,_rectSize));
    this->_shape.setPosition((row*_rectSize + 15),(col*_rectSize + 10));

    this->_shape.setOutlineColor(sf::Color::White);
    this->_shape.setOutlineThickness(2.f);
    this->_shape.setFillColor(sf::Color(220,220,220));
    this->_bounds = this->_shape.getGlobalBounds();
    this->_position.setX(row);
    this->_position.setY(col);
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

int Cell::getCurrentCellSize() const
{
    return _currentCellSize;
}

sf::FloatRect Cell::getRectBounds() const
{
    return this->_bounds;
}

float &Cell::getRectSize()
{
    return _rectSize;
}

void Cell::setRectBounds(sf::FloatRect fr)
{
    this->_bounds = fr;
}

bool Cell::operator==(const Cell &cell) const
{
    return(_alive == cell._alive && _position.operator==(cell._position));
}

bool Cell::operator!=(const Cell &cell)
{
    return !(this->operator==(cell));
}