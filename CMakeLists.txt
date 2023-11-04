cmake_minimum_required(VERSION 3.0)
project(Game_of_life_graphique)

# Recherchez la bibliothèque SFML
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Incluez les en-têtes de SFML
include_directories(${SFML_INCLUDE_DIR})

# Ajoutez vos fichiers source
add_executable(Game_of_life src/main.cpp src/Menu.cpp src/Position.cpp src/GameSetting.cpp 
                src/GameBoard.cpp src/Game.cpp src/Cell.cpp)

# Liez votre programme avec la bibliothèque SFML
target_link_libraries(Game_of_life sfml-graphics sfml-window sfml-system)