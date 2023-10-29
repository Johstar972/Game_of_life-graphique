#include "../header/Cell.hpp"
#include "../header/Grid.hpp"
#include "../header/constants.hpp"
#include <SFML/Graphics/RenderWindow.hpp>


Grid::Grid(sf::RenderWindow &window, int row, int col)
{
    //On donne aux attributs la valeur de ligne et de colonne que l'utilisateur a choisie
    _row = row; _col = col;
    float rectsize = 30.f;

    if(_row > 50 && _col > 34 && _row <= 60 && _col <= 40)
    {
        rectsize = 25.f;
    }
    else if(_row > 60 && _col > 40 && _row <= 75 && _col <= 50)
    {
        rectsize = 20.f;
    }
    else if(_row > 60 && _col > 40 && _row <= 150 && _col <= 100)
    {
        rectsize = 10.f;
    }
    else if(_row > 150 && _col > 100 && _row <= 300 && _col <= 200)
    {
        rectsize = 5.f;
    }
    //On stock dans deux variables le point ou commencera le dessin de la grille en fonction du nombre de ligne et de colonne
    int startPointRow = ((window.getSize().x - (row * rectsize)) / 2) - 250;
    int startPointCol = ((window.getSize().y - (col * rectsize)) / 2);

    //On ajuste la taille du vector
    _cells.resize(_row,std::vector<Cell>(_col));

    //On parcours le vecteur et l'on intialise chaque cellule 
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            shape.setSize(sf::Vector2f(rectsize,rectsize));
            shape.setPosition((i*rectsize + startPointRow),(j*rectsize + startPointCol));

            shape.setOutlineColor(sf::Color::White);
            shape.setOutlineThickness(2.f);
            shape.setFillColor(sf::Color::Black);
            _cells[i][j].setRectBounds(shape.getGlobalBounds());
            _cells[i][j].setPosition(i,j);
            
        }
    }
}


Grid::~Grid(){}


void Grid::cellIsClicked(int mouseX, int mouseY)
{
    for(int i = 0; i < _cells.size(); i++)
    {
        for(int j = 0; j < _cells[i].size(); j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            if(_cells[i][j].getRectBounds().contains(mouseX,mouseY))
            {
                if(_cells[i][j].getAlive() == 0)
                {
                    _cells[i][j].setAlive(1);
                    std::cout << "j'ai cliqué sur une cellule" << std::endl;
                    shape.setFillColor(sf::Color(255,255,0));
                    std::cout << _cells[i][j] << std::endl;
                    break;
                    
                }
                else
                {
                    _cells[i][j].setAlive(0);
                    std::cout << "j'ai cliqué sur une cellule" << std::endl;
                    shape.setFillColor(sf::Color::Black);
                    std::cout << _cells[i][j] << std::endl;
                    break;
                    
                }
            }
        }
    }

    //TODO:Trouvé un moyen de le faire avec un while sans break

    // int i = 0, j = 0;
    // bool found = false;
    // while(found == false && (i <= _cells.size() && j <=_cells[i].size()))
    // {
    //     sf::RectangleShape &shape = _cells[i][j].getShape();
    //     if(_cells[i][j].getRectBounds().contains(mouseX,mouseY))
    //     {
    //         if(_cells[i][j].getAlive() == 0)
    //         {
    //             _cells[i][j].setAlive(1);
    //             std::cout << "j'ai cliqué sur une cellule" << std::endl;
    //             shape.setFillColor(sf::Color(255,255,0));
    //             std::cout << _cells[i][j] << std::endl;
    //             found = true;
    //         }
    //         else
    //         {
    //             _cells[i][j].setAlive(0);
    //             std::cout << "j'ai cliqué sur une cellule" << std::endl;
    //             shape.setFillColor(sf::Color::Black);
    //             std::cout << _cells[i][j] << std::endl;
    //             found = true;
    //         }
    //     }
    //     else if(i == _cells.size())
    //     {
    //         i = 0;
    //         j++;
    //     }
    //     else
    //     {
    //         i++;
    //     }
    // }
}

void Grid::update(sf::RenderWindow &window)
{
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
        
            window.draw(shape);
        }
    }
}