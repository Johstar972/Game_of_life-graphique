#include "Cell.hpp"

class Grid
{
private:
    std::vector<std::vector<Cell>> _cells;
    int _row, _col;
public:
    Grid();
    ~Grid();

    void init(sf::RenderWindow &window, int row, int col);
    void draw(sf::RenderWindow &window);
};

