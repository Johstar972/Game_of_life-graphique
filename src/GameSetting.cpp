#include "../header/GameSetting.hpp"
#include "../header/constants.hpp"
#include <iostream>

GameSetting::GameSetting()
{
    _width = WIDTH_GAME_SETTING; _height = HEIGHT_GAME_SETTING;

    
    _shapes.resize(NB_RECT);
    for(int i = 0; i < _shapes.size(); i++)
    {
        if(i > 0)
            _shapes[i].setFillColor(sf::Color::Black);
        switch (i)
        {
        case 0:
            _shapes[i].setSize(sf::Vector2f(_width,_height));
            _shapes[i].setPosition((WIDTH_GAME - WIDTH_GAME_SETTING), 0);

            if(!_texture.loadFromFile("../image_fonts/brick.jpg"))
                std::cerr<<"picture not found";
            
            _shapes[i].setTexture(&_texture);
            break;
            
        case 1:
            _shapes[i].setSize(sf::Vector2f(400,400));
            _shapes[i].setPosition(1550, 200);
            break;
        
        case 2:
            _shapes[i].setSize(sf::Vector2f(100,80));
            _shapes[i].setPosition(1630,680);
            break;

        case 3:
            _shapes[i].setSize(sf::Vector2f(100,80));
            _shapes[i].setPosition(1785,680);
            break;
        }
    }

    if(!_font.loadFromFile("../image_fonts/Roboto-Light.ttf"))
       std::cerr<<"font not found"<<std::endl;

    
    //On initialise la taille du tableau de bouton textuel
    _buttonSetting.resize(BUTTONS_GAME_SETTING);
    

    //On parcourt la liste de bouton pour les initialiser
    for(int i = 0; i < _buttonSetting.size(); i++)
    {
        _buttonSetting[i].setFont(_font);
        _buttonSetting[i].setFillColor(sf::Color::White);
        _buttonSetting[i].setCharacterSize(50);

        switch (i)
        {
        case 0:
            _buttonSetting[i].setString("Start");
            _buttonSetting[i].setPosition(1550,50);
            break;
        case 1:
            _buttonSetting[i].setString("Stop");
            _buttonSetting[i].setPosition(1700,50);
            break;
        case 2:
            _buttonSetting[i].setString("Clear");
            _buttonSetting[i].setPosition(1850,50);
            break;

        case 3:
            _buttonSetting[i].setString(L"Main menu");
            _buttonSetting[i].setPosition(1625,850);
            break;
        case 4:
            _buttonSetting[i].setString("row");
            _buttonSetting[i].setPosition(1640,750);
            
            break;
        case 5:
            _buttonSetting[i].setString("col");
            _buttonSetting[i].setPosition(1795,750);
            break;
        }

    } 
}
    
GameSetting::~GameSetting(){}

std::vector<sf::RectangleShape> GameSetting::getShapes() const
{
    return _shapes;
}

const std::vector<sf::Text> &GameSetting::getButtonSetting() const
{
    return _buttonSetting;
}



