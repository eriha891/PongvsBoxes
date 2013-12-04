#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Game
{
public:
    Game();

    void run();

    void handlePlayerInput(sf::Keyboard::Key, bool pressed);

private:
    void processEvents();
    void update(sf::Time TimePerFrame);
    void render();

    sf::RenderWindow mWindow;
    sf::CircleShape mPlayer;

    bool mIsMovingLeft;
    bool mIsMovingRight;
};
