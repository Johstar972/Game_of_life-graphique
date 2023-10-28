#include "../header/Position.hpp"


Position::Position()
{
    this->_x = 0, this->_y = 0;
}

Position::Position(const Position &position)
{
    this->_x = position._x, this->_y = position._y;
}

Position::Position(int x, int y)
{
    this->_x = x, this->_y = y;
}

int Position::getX() const
{
    return this->_x;
}

int Position::getY() const
{
    return this->_y;
}


// std::ostream& operator<<(std::ostream& os, Position& position)
// {
//     os << "X : "<< position._x <<", Y : "<< position._y << std::endl;

//      return os;
// }

// bool Position::operator==(const Position &position) const
// {
//     return (_x == position._x && _y == position._y);
  
// }