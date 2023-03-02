#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

class Game
{
public:

    Game();
    void run();

private:
    void processEvents();//handles user input
    void update();//updates game logic
    void render();

private:
    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;
    
};
