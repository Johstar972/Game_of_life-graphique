#include "../header/GameSetting.hpp"
#include "../header/constants.hpp"
#include <iostream>

GameSetting::GameSetting()
{
    _width = WIDTH_GAME_SETTING; _height = HEIGHT_GAME_SETTING;
    _shapes.resize(2);
    
    _shapes[0].setSize(sf::Vector2f(_width,_height));
    _shapes[0].setPosition((WIDTH_GAME - WIDTH_GAME_SETTING), 0);

    if(!_texture.loadFromFile("../image_fonts/brick.jpg"))
        std::cerr<<"picture not found";
    
    _shapes[0].setTexture(&_texture);

    _shapes[1].setSize(sf::Vector2f(400,400));
    _shapes[1].setPosition(1550, 200);
    _shapes[1].setFillColor(sf::Color::Black);

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
            _buttonSetting[i].setPosition(1625,800);
            break;
        case 4:
            _buttonSetting[i].setString("-->");
            _buttonSetting[i].setPosition(1800,650);
            break;
        case 5:
            _buttonSetting[i].setString("<--");
            _buttonSetting[i].setPosition(1655,650);
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



