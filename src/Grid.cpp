#include "../header/Cell.hpp"
#include "../header/Grid.hpp"
#include "../header/constants.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


Grid::Grid(){}


Grid::~Grid(){}

void Grid::init(sf::RenderWindow &window, int row, int col)
{
    //std::min prend la plus petite valeur des deux et std::max prend la plus grande
    //On peut donc déterminer la taille adéquat de la cellule
    _row = row; _col = col;
    unsigned int windowWidth = rectSize * row; //La largeur de la fenetre devient nb row * la taille d'une cellule
    unsigned int windowHeight = rectSize * col;// La hauteur de la fenetre devient nb col * la taille d'une cellule

    window.setSize(sf::Vector2u(windowWidth, windowHeight));// On ajuste la taille de la fenetre

}

void Grid::draw(sf::RenderWindow &window)
{
    _cells.resize(_row,std::vector<Cell>(_col)); //On ajuste la taille du vector
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            shape.setSize(sf::Vector2f(rectSize,rectSize));
            shape.setPosition(i*rectSize,j*rectSize);

            shape.setOutlineColor(sf::Color::White);
            shape.setOutlineThickness(2.f);
            shape.setFillColor(sf::Color::Black);
            _cells[i][j].setRectBounds(shape.getGlobalBounds());
            _cells[i][j].setPosition(i,j);
            window.draw(shape);
        }
    }
}