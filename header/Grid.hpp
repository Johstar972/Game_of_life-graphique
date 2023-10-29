#include "Cell.hpp"

class Grid
{
private:
    std::vector<std::vector<Cell>> _cells;
    int _row, _col;
public:

    /**
     * @brief Constructeur de la class Grid avec paramètre
     * 
     * @param window La fenêtre
     * @param row Le nombre de ligne pour les cellules
     * @param col Le nombre de colonne pour les cellules
     */
    Grid(sf::RenderWindow &window, int row, int col);

    /**
     * @brief Destructeur de la class Grid
     * 
     */
    ~Grid();

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
};

