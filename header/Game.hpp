#include <SFML/Graphics/RenderWindow.hpp>

class Game
{
private:
    sf::RenderWindow window;
    const sf::Time TIME_PER_SECOND = sf::seconds(1.f/60.f);
public:
    Game();
    ~Game();

    void run();
};


