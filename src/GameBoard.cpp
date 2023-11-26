#include "../header/Cell.hpp"
#include "../header/GameBoard.hpp"
#include "../header/constants.hpp"
#include <SFML/Graphics/RenderWindow.hpp>
#include <math.h>
#include <random>
#include <ctime>
#include <chrono>


GameBoard::GameBoard(sf::RenderWindow &window, int row, int col)
{
    
    _row = row; _col = col;

    
    _cells.resize(_row,std::vector<Cell>(_col));

    
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            _cells[i][j].initShape(i,j);
            
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
                    break;
                    
                }
                else
                {
                    _cells[i][j].setAlive(0);
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

    
    stats();

    for(auto &shapeSetting : _gameSetting.getShapes())
    {
        window.draw(shapeSetting);
    }
        
    const std::vector<sf::Text> &buttons = _gameSetting.getButtonSetting();
    for(int i = 0; i < buttons.size(); i++)
    {
        window.draw(buttons[i]);
    }

    std::vector<sf::Text> texts = _gameSetting.getText();
    for(int i = 0; i < texts.size(); i ++)
    {
        window.draw(texts[i]);
        
    }
    
}

bool GameBoard::buttonTextIsClicked(int mouseX, int mouseY, bool state)
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
                clearGameBoard();
                break;
            case 3: 
                std::cout << "bouton main menu"<< std::endl;
                if(state == true)
                    state = false;
                    clearGameBoard();
                    _canChange = false;
                    return state;
                //Faire en sorte que _isRun passe a false
                break;
            case 4:
                setSizeOfGrid(i);
                break;

            case 5:
                setSizeOfGrid(i);
                break;

            case 6:
                setSizeOfGrid(i);
                break;

            case 7:
                setSizeOfGrid(i);
                break;
            case 8:
                fillGridFully();
                break;
            case 9:
                fillCheckerBoard();
                break;
            case 10:
                fillGridRandom();
            }
            
        }
    }
    
    return true;
}

void GameBoard::setSizeOfGrid(int buttonId)
{
    int numericValue = 0;
    std::string newValueString = "";
    std::string stringValue = "";
    std::vector<sf::Text> &texts = _gameSetting.getText();

    if (buttonId == 4 || buttonId == 5)
    {
        stringValue = texts[0].getString().toAnsiString();
    }
    else
    {
        stringValue = texts[1].getString().toAnsiString();
    }

    try
    {
        numericValue = std::stoi(stringValue);
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "Erreur : la conversion en entier a échoué (argument invalide)" << std::endl;
    }
    catch (const std::out_of_range &e)
    {
        std::cerr << "Erreur : la conversion en entier a échoué (dépassement de capacité)" << std::endl;
    }

    switch (buttonId)
    {
    case 4:
        if (_row > 0)
            numericValue += -1;
        // Convertir la nouvelle valeur en std::string
        newValueString = std::to_string(numericValue);

        texts[0].setString(newValueString);
        _row = numericValue;

        _cells.resize(_row, std::vector<Cell>(_col));
        for (int i = 0; i < _row; i++)
        {
            _cells[i].resize(_col);
            for (int j = 0; j < _col; j++)
            {
                _cells[i][j].initShape(i, j);
            }
        }

        break;

    case 5:

        if (_row < NB_ROW)
            numericValue += 1;
        // Convertir la nouvelle valeur en std::string
        newValueString = std::to_string(numericValue);

        texts[0].setString(newValueString);
        _row = numericValue;

        _cells.resize(_row, std::vector<Cell>(_col));
        for (int i = 0; i < _row; i++)
        {
            _cells[i].resize(_col);
            for (int j = 0; j < _col; j++)
            {
                _cells[i][j].initShape(i, j);
            }
        }

        break;

    case 6:
        if (_col > 0)
            numericValue += -1;
        // Convertir la nouvelle valeur en std::string
        newValueString = std::to_string(numericValue);

        texts[1].setString(newValueString);
        _col = numericValue;

        // Redimensionner chaque ligne à l'intérieur de _cells
        for (int i = 0; i < _row; i++)
        {
            _cells[i].resize(_col);
            for (int j = 0; j < _col; j++)
            {
                _cells[i][j].initShape(i, j);
            }
        }

        break;

    case 7:
        if (_col < NB_COL)
            numericValue += 1;
        // Convertir la nouvelle valeur en std::string
        newValueString = std::to_string(numericValue);

        texts[1].setString(newValueString);
        _col = numericValue;

        // Redimensionner chaque ligne à l'intérieur de _cells
        for (int i = 0; i < _row; i++)
        {
            _cells[i].resize(_col);
            for (int j = 0; j < _col; j++)
            {
                _cells[i][j].initShape(i, j);
            }
        }

        break;
    }
}


void GameBoard::evolve()
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

void GameBoard::fillGridFully()
{
    for(int i = 0; i < _cells.size(); i++)
    {
        for(int j = 0; j <_cells[i].size(); j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            _cells[i][j].setAlive(1);
        }
    }
}

void GameBoard::fillCheckerBoard()
{
    for(int i = 0; i < _cells.size(); i++)
    {
        for(int j = 0; j <_cells[i].size(); j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            if ((i + j) % 2 != 0) {
                _cells[i][j].setAlive(1);
            }
        }
    }
}

void GameBoard::fillGridRandom()
{
    srand(time(NULL));
    int nbCells = rand() % ((400 - 1) - 250 + 1) + 250;

    for (int k = 0; k < nbCells; k++)
    {
        int i = std::rand() % _cells.size();
        int j = std::rand() % _cells[i].size();

        sf::RectangleShape &shape = _cells[i][j].getShape();

        _cells[i][j].setAlive(1);
        
    }
}

#include <iomanip>  // Pour std::setprecision
#include <sstream>  // Pour std::ostringstream

void GameBoard::stats()
{
    int nbCellsAlive = 0, nbCellsDead = 0;
    double pCellsAlive = 0.0, pCellsDead = 0.0;

    // Calcul des statistiques
    for (int i = 0; i < _cells.size(); i++)
    {
        for (int j = 0; j < _cells[i].size(); j++)
        {
            if (_cells[i][j].getAlive() == 1)
                nbCellsDead += 1;
            else
                nbCellsAlive += 1;
        }
    }

    // Calcul des pourcentages
    int totalCells = _cells.size() * _cells[0].size();
    pCellsAlive = (static_cast<double>(nbCellsAlive) / totalCells) * 100;
    pCellsDead = (static_cast<double>(nbCellsDead) / totalCells) * 100;

    // Conversion des pourcentages en chaînes avec un chiffre après la virgule
    std::ostringstream pCellsDeadStream, pCellsAliveStream;
    pCellsDeadStream << std::fixed << std::setprecision(1) << pCellsDead;
    pCellsAliveStream << std::fixed << std::setprecision(1) << pCellsAlive;

    // Mise à jour des textes
    std::vector<sf::Text> &texts = _gameSetting.getText();
    texts[2].setString("Cellule(s) vivante(s) -> " + pCellsDeadStream.str() + "%");
    texts[3].setString("Cellule(s) morte(s) -> " + pCellsAliveStream.str() + "%");
}


void GameBoard::clearGameBoard()
{
    for(int i = 0; i < _row; i++)
    {
        for(int j = 0; j < _col; j++)
        {
            sf::RectangleShape &shape = _cells[i][j].getShape();
            if(_cells[i][j].getAlive() == 1)
                _cells[i][j].setAlive(0);
            
        }
    }
}