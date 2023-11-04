#include "../header/Menu.hpp"
#include "../header/constants.hpp"

Menu::Menu()
{
    
    _width = WIDTH_MENU; _height = HEIGHT_MENU;
    if(!_font.loadFromFile("../image_fonts/Roboto-Light.ttf"))//On essaye de charger la font
        std::cerr<<"font not found"<<std::endl;
    
    _buttonList.resize(BUTTONS_MENU);//On initialise le vecteur de bouton

    //On parcourt la liste de bouton pour les initialiser
    for(int i = 0; i < _buttonList.size(); i++)
    {
        _buttonList[i].setFont(_font);
        _buttonList[i].setFillColor(sf::Color::White);
        _buttonList[i].setCharacterSize(70);

        if(i == 0)
        {
            _buttonList[i].setString("Play");
            _buttonList[i].setPosition(900,250);
        }
        else if(i == 1)
        {
            _buttonList[i].setString("Quit");
            _buttonList[i].setPosition(900,350);
            
            
        }
    }

    //On essaye de charger l'image
    if(!_gameTitleTexture.loadFromFile(("../image_fonts/main_menu_title.png")))
        std::cerr << "picture not found";
    
    
    _gameTitleSprite.setTexture(_gameTitleTexture);
    _gameTitleSprite.setPosition(600,75);
    
        
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