#include "../header/Menu.hpp"

Menu::Menu()
{
    
    _width = 400; _height = 600;
    if(!_font.loadFromFile("../image_fonts/Roboto-Light.ttf"))
        std::cout<<"font not found"<<std::endl;
    
    _buttonList.resize(4);
    for(int i = 0; i < _buttonList.size(); i++)
    {
        _buttonList[i].setFont(_font);
        _buttonList[i].setFillColor(sf::Color::White);
        _buttonList[i].setCharacterSize(70);

        if(i == 0)
        {
            _buttonList[i].setString("Play");
            _buttonList[i].setPosition(425,250);
        }
        else if(i == 1)
        {
            _buttonList[i].setString("Quit");
            _buttonList[i].setPosition(425,350);
            
            
        }
    }

    
    if(!_gameTitleTexture.loadFromFile(("../image_fonts/main_menu_title.png")))
        std::perror("picture not found");
    
    
    _gameTitleSprite.setTexture(_gameTitleTexture);
    //_gameTitle.setTextureRect(sf::IntRect(150,100,400,100));
    _gameTitleSprite.setPosition(120,75);
    
        
}



Menu::~Menu(){}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < _buttonList.size(); i++)
    {
        window.draw(_buttonList[i]);
    }
}

std::vector<sf::Text> Menu::getButtonList() const
{
    return _buttonList;
}

sf::Sprite Menu::getGameTitle() const
{
    return _gameTitleSprite;
}