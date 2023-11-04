#define CONSTANTS_H
#ifndef CONSTANT_H

#include <SFML/Graphics.hpp>
#include <array>

const std::vector<sf::VideoMode> SCREEN = sf::VideoMode::getFullscreenModes();

//Grid
const int WIDTH_GAME = 2000;
const int HEIGHT_GAME = 1000;

//Menu
const int BUTTONS_MENU = 4;
const int WIDTH_MENU = 1000;
const int HEIGHT_MENU = 1000;

//Game setting
const int BUTTONS_GAME_SETTING = 6;
const float WIDTH_GAME_SETTING = 500.f;
const float HEIGHT_GAME_SETTING = 1000.f;

//Cell
const float SIZES[8] = {14.5f, 19.5f, 24.5f, 29.5f, 34.5f, 39.5f, 44.5f, 49.5f};
const int NB_SIZE_CELL = 8;
#endif