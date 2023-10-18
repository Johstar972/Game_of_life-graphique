#include "../header/menu.hpp"

Menu::Menu()
{
    _width = 400; _height = 600;
    if(!font.loadFromFile("../image_fonts/Roboto-Light.ttf"))
        std::cout<<"font not found"<<std::endl;
    
    buttonList.resize(4);
    for(int i = 0; i < buttonList.size(); i++)
    {
        buttonList[i].setFont(font);
        buttonList[i].setFillColor(sf::Color::White);
        buttonList[i].setCharacterSize(70);

        if(i == 0)
        {
            buttonList[i].setString("Play");
            buttonList[i].setPosition(300,200);
        }
        else if(i == 1)
        {
            buttonList[i].setString("Quit");
            buttonList[i].setPosition(400,200);
        }
    }
}

Menu::~Menu(){}

void Menu::draw(sf::RenderWindow &window)
{
    for(int i = 0; i < buttonList.size(); i++)
    {
        window.draw(buttonList[i]);
    }
}