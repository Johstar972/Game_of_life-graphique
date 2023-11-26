#ifndef GAMEBOARD_HPP
#define GAMEBOARD_HPP

#include "Cell.hpp"
#include "GameSetting.hpp"

/**
 * @brief Class GameBoard représente la grille de jeu
 * 
 */
class GameBoard
{
private:
    std::vector<std::vector<Cell>> _cells;
    int _currentSizeCell;
    int _row, _col;
    bool _canChange = false;
    GameSetting _gameSetting;
public:

    /**
     * @brief Constructeur de la class GameBoard avec paramètre
     * 
     * @param window La fenêtre
     * @param row Le nombre de ligne pour les cellules
     * @param col Le nombre de colonne pour les cellules
     */
    GameBoard(sf::RenderWindow &window, int row, int col);

    /**
     * @brief Destructeur de la class GameBoard
     * 
     */
    ~GameBoard();

    /**
     * @brief Cette fonction membre indiquera si l'on a cliquer sur une cellule
     * 
     * @param mouseX Le point x de la position de la souris
     * @param mouseY Le point y de la position de la souris
     */
    void cellIsClicked(int mouseX, int mouseY);

    /**
     * @brief Fonction membre permettant de mettre a jour la fenêtre
     * 
     * @param window La fenêtre
     */
    void update(sf::RenderWindow &window);

    /**
     * @brief Cette fonction membre augmentera ou diminuera la taille et le nombre de cellule en ligne et colonne
     * 
     */
    void setSizeOfGrid(int buttonId);

    /**
     * @brief Cette fonction membre permettra de réaliser une action en cliquant sur les boutons textuels
     * 
     * @param mouseX Le point x de la position de la souris
     * @param mouseY Le point y de la position de la souris
     * @param state L'état du jeu
     * @return true Si le jeu est toujours en marche
     * @return sinon false 
     */
    bool buttonTextIsClicked(int mouseX, int mouseY, bool state);

    /**
     * @brief Méthode permetant de vérifier le nombre de voisin mort et vivant autour d'une cellule
     * 
     * @param x La position x de la cellule dont on veut vérifier les voisins
     * @param y La position y de la cellule dont on veut vérifier les voisins
     * @param copygrid La copie du tableau en cours
     * @return std::tuple<int, int> 
     */
    std::tuple<int, int> isArround(int x, int y, const std::vector<std::vector<Cell>> &copygrid);

    /**
     * @brief //Methode permettant de faire evoluer selon les regles 
     * les cellules vers la gen suivante
     */
    void evolve();

    /**
     * @brief Fonction membre permettant de supprimer toute les cellules vivantes
     * 
     */
    void clearGameBoard();

    /**
     * @brief Fonction membre permettant de mettre tout les cellules vivantes
     * 
     */
    void fillGridFully();

    /**
     * @brief Fonction membre permettant de remplir le tableau de cellule vivantes comme un damier
     * 
     */
    void fillCheckerBoard();

    /**
     * @brief Fonction membre permettant de remplir le tableau de manière aléatoire de cellule vivante
     * 
     */
    void fillGridRandom();

    /**
     * @brief Fonction membre permettant d'afficher des statistiques 
     * 
     */
    void stats();

    /**
     * @brief Fonction membre permettant de récupérer le nombre de ligne sur le tableau
     * 
     * @return int 
     */
    int getNumberRow() const;

    /**
     * @brief Fonction membre permettant de récupérer le nombre de colonne sur le tableau
     * 
     * @return int 
     */
    int getNumberCol() const;

    /**
     * @brief Fonction membre permettant de savoir si le tableau peut changer
     * 
     * @return true 
     * @return false 
     */
    bool getIsChange() const;

    /**
     * @brief Fonction membre permettant de modifier le nombre de ligne du tableau
     * 
     * @param newNumberRow 
     */
    void setNumberRow(int newNumberRow);

    /**
     * @brief Fonction membre permettant de modifier le nombre de colonne du tableau
     * 
     * @param newNumberCol 
     */
    void setNumberCol(int newNumberCol);

    /**
     * @brief Méthode permettant de redéfinir l'opérateur ==
     * 
     * @param grid L'objet Grid à comparer avec l'objet courant
     * @return true Si les deux éléments sont égaux
     * @return false Si les deux éléments ne sont pas égaux
     */
    bool operator ==(const GameBoard &gb);

};

inline void GameBoard::setNumberRow(int newNumberRow)
{
    _row = newNumberRow;
}

inline void GameBoard::setNumberCol(int newNumberCol)
{
    _col = newNumberCol;
}

#endif