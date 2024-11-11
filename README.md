# Game of life graphique

## Installation et Configuration de SFML pour Game of Life Graphique

Ce guide explique comment installer et configurer la bibliothèque SFML (Simple and Fast Multimedia Library) sur Linux pour le projet "Game of Life Graphique". Il inclut également des instructions sur la configuration du fichier CMakeLists.txt et du fichier tasks.json pour la compilation et l'exécution du projet.

* ### Installation de SFML sur Linux

    1- Installation des dépendances:

    Assurez-vous d'installer les dépendances nécessaires avant d'installer SFML.

    ```bash
    sudo apt-get update
    sudo apt-get install libsfml-dev

    ```

    2- Vérification de l'installation:

    Assurez-vous que SFML est correctement installé en vérifiant la version.

    ```bash
    pkg-config --modversion sfml-all

    ```
* ### Configuration du CMakeLists.txt

    Modifiez votre fichier CMakeLists.txt comme suit :

    ```cmake
    cmake_minimum_required(VERSION 3.0)
    project(Game_of_life_graphique)

    # Recherchez la bibliothèque SFML
    find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

    # Ajoutez vos fichiers source
    add_executable(Game_of_life src/main.cpp src/Menu.cpp src/Position.cpp src/GameSetting.cpp 
                    src/GameBoard.cpp src/Game.cpp src/Cell.cpp)

    # Liez votre programme avec la bibliothèque SFML
    target_link_libraries(Game_of_life sfml-graphics sfml-window sfml-system)

    ```
* ### [Optionnel]Configuration du fichier tasks.json pour Visual Studio Code

    Modifiez votre fichier tasks.json pour permettre la compilation et l'exécution depuis Visual Studio Code. Assurez-vous de mettre à jour le chemin vers les fichiers d'en-tête et les bibliothèques SFML selon votre configuration.

    ```json
    {
        "tasks": [
            {
                "type": "cppbuild",
                "label": "C/C++: g++ build active file",
                "command": "/usr/bin/g++",
                "args": [
                    "-fdiagnostics-color=always",
                    "-g",
                    "${workspaceFolder}/src/main.cpp",
                    "Menu.cpp",
                    "Cell.cpp",
                    "GameBoard.cpp",
                    "Game.cpp",
                    "Position.cpp",
                    "GameSetting.cpp",
                    "-o",
                    "${workspaceFolder}/src/Game_of_life",
                    "-I/usr/include/SFML",       
                    // Chemin vers les fichiers d'en-tête de SFML
                    "-L/usr/lib/x86_64-linux-gnu",                 
                    // Chemin vers les bibliothèques de SFML
                    "-lsfml-graphics",
                    "-lsfml-window",
                    "-lsfml-system",
                ],
                "options": {
                    "cwd": "${fileDirname}"
                },
                "problemMatcher": [
                    "$gcc"
                ],
                "group": {
                    "kind": "build",
                    "isDefault": true
                },
                "detail": "Task generated by Debugger."
            }
        ],
        "version": "2.0.0"
    }

    ```

    Assurez-vous d'ajuster le chemin vers les fichiers d'en-tête et les bibliothèques SFML en fonction de votre installation.

    Avec ces configurations, vous devriez être en mesure de compiler et d'exécuter mon projet Game of Life Graphique depuis Visual Studio Code sur Linux.