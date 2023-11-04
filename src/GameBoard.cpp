#include "../header/Cell.hpp"
#include "../header/GameBoard.hpp"
#include "../header/constants.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <math.h>


GameBoard::GameBoard(sf::RenderWindow &window, int row, int col)
{
    
    //On donne aux attributs la valeur de ligne et de colonne que l'utilisateur a choisie
    this->setNumberRow(row); this->setNumberCol(col);
    this->_currentSizeCell = 1;
    // if(_row > 50 && _col > 34 && _row <= 60 && _col <= 40)
    // {
    //     rectsize = 25.f;
    // }
    // else if(_row > 60 && _col > 40 && _row <= 75 && _col <= 50)
    // {
    //     rectsize = 20.f;
    // }
    // else if(_row > 60 && _col > 40 && _row <= 150 && _col <= 100)
    // {
    //     rectsize = 10.f;
    // }
    // else if(_row > 150 && _col > 100 && _row <= 300 && _col <= 200)
    // {
    //     rectsize = 5.f;
    // }
    //On stock dans deux variables le point ou commencera le dessin de la grille en fonction du nombre de ligne et de colonne
    // int startPointRow = ((window.getSize().x - (row * rectsize)) / 2) - 250;
    // int startPointCol = ((window.getSize().y - (col * rectsize)) / 2);

    //On ajuste la taille du vector
    _cells.resize(_row,std::vector<Cell>(_col));

    //On parcours le vecteur et l'on intialise chaque cellule 
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            _cells[i][j].setCurrentCellSize(SIZES[_currentSizeCell]);
            float &size = _cells[i][j].getRectSize();
            sf::RectangleShape &shape = _cells[i][j].getShape();
            shape.setSize(sf::Vector2f(size,size));
            shape.setPosition((i*size + 15),(j*size + 10));

            shape.setOutlineColor(sf::Color::White);
            shape.setOutlineThickness(2.f);
            shape.setFillColor(sf::Color(220,220,220));
            _cells[i][j].setRectBounds(shape.getGlobalBounds());
            _cells[i][j].setPosition(i,j);
            
        }
    }

}


GameBoard::~GameBoard(){}

int GameBoard::getNumberRow() const
{
    return _row;
}

int GameBoard::getNumberCol() const
{
    return _col;
}

bool GameBoard::getIsChange() const
{
    return _canChange;
}

bool GameBoard::operator==(const GameBoard &gb)
{
    if(!(this->_cells.size() == gb._cells.size() || this->_cells[0].size() == gb._cells[0].size()))
        return false;
    
    for(int i = 0; i < _cells.size(); i++)
    {
        for(int j = 0; j < _cells[i].size(); j++)
        {
            if(_cells[i][j] != gb._cells[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

void GameBoard::cellIsClicked(int mouseX, int mouseY)
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
                    shape.setFillColor(sf::Color(255,255,0));
                    break;
                    
                }
                else
                {
                    _cells[i][j].setAlive(0);
                    shape.setFillColor(sf::Color(220,220,220));
                    break;
                    
                }
            }
        }
    }

}

void GameBoard::update(sf::RenderWindow &window)
{
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
        
            window.draw(shape);
        }
    }

    for(auto &shapeSetting : _gameSetting.getShapes())
    {
        window.draw(shapeSetting);
    }
        
    const std::vector<sf::Text> &buttons = _gameSetting.getButtonSetting();
    for(int i = 0; i < buttons.size(); i++)
    {
        window.draw(buttons[i]);
    }

    std::cout << "maj" << std::endl;
    
}

void GameBoard::buttonTextIsClicked(int mouseX, int mouseY, bool state, sf::RenderWindow &window)
{
    const std::vector<sf::Text> &buttons = _gameSetting.getButtonSetting();

    for(int i = 0; i < buttons.size(); i++)
    {
        if(buttons[i].getGlobalBounds().contains(mouseX,mouseY))
        {
            switch (i)
            {
            case 0: 
                std::cout << "bouton start" << std::endl;
                _canChange = true;
                break;
            case 1: 
                std::cout << "bouton stop" << std::endl;
                _canChange = false;
                break;
            case 2: 
                std::cout << "bouton clear"<< std::endl;
                clearGameBoard(window);
                break;
            case 3: 
                std::cout << "bouton main menu"<< std::endl;
                //Faire en sorte que _isRun passe a false
                break;
            case 4: 
                this->changeCellSize(i);
                break;
            case 5: 
                this->changeCellSize(i);
                break;
        
            }
            
        }
    }
}

void GameBoard::changeCellSize(int buttonId)
{
    if(buttonId == 4)
    {
        std::cout << "J'augmente le nombre de cellule et leurs taille";
        //On augmente la taille de la cellule
        _currentSizeCell += 1;
        for(int i = 0; i < _row; i++)
        {
            for(int j = 0; j < _col; j++)
            {
                
                _cells[i][j].setCurrentCellSize(_currentSizeCell);
            
                //window.draw(shape);
            }
        }
        _row = std::floor(WIDTH_GAME / SIZES[_currentSizeCell]);
        
        _cells.resize(_row,std::vector<Cell>(_col));
    }
    else if(buttonId == 5)
    {
        std::cout << "Je diminue le nombre de cellule sur les lignes";
        
        if(_row > 4)
            this->setNumberRow(_row - 1);
            _cells.resize(_row,std::vector<Cell>(_col));
    }
    
}

void GameBoard::evolve(sf::RenderWindow& window)
{
    
    std::vector<std::vector<Cell>> copygrid = _cells;
    
    for(int i = 0; i < _cells.size(); i++)
    {
        for(int j = 0; j <_cells[i].size(); j++)
        {
            std::tuple<int,int> nbCellArround = this->isArround(i,j, copygrid);
            
            if(_cells[i][j].getAlive() == 1 && std::get<0>(nbCellArround) < 2)
            {
                _cells[i][j].setAlive(0);
                
            }
            else if(_cells[i][j].getAlive() == 1 && std::get<0>(nbCellArround) > 3)
            {
                _cells[i][j].setAlive(0);
                
            }
            else if(_cells[i][j].getAlive() == 0 && std::get<0>(nbCellArround) == 3)
            {
               _cells[i][j].setAlive(1);
               
            }
            
        }
    }
    // if(_cells == copygrid)
    // {
    //     _canChange = false;
    // }

}

std::tuple<int,int> GameBoard::isArround(int x, int y, const std::vector<std::vector<Cell>> &copygrid)
{
    
    int nbCellInLife = 0;
    int nbCellDead = 0;
    
    for( int i = -1; i <= 1; i++)
    {
        for(int j = -1; j <= 1; j++)
        {
            int newX = x + i;
            int newY = y + j;

            if(newX >= 0 && newX < _cells.size() && newY >= 0 && newY < _cells[0].size())
            {
                if(newX != x || newY != y)
                {
                    if(copygrid[newX][newY].getAlive() == 0) 
                    {
                        nbCellDead +=1;
                    }
                    else
                    {
                        nbCellInLife += 1;
                    }
                }
                
            }
        }
    }

    return std::make_tuple(nbCellInLife, nbCellDead);
}

void GameBoard::clearGameBoard(sf::RenderWindow &window)
{
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            if(_cells[i][j].getAlive() == 1)
                _cells[i][j].setAlive(0);
            shape.setFillColor(sf::Color::Black);
        }
    }
}