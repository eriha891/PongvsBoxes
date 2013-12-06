#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"

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
    sf::RectangleShape mPlayer;
    sf::CircleShape mBall;
    sf::RectangleShape testBlock;

    int blockLife;

    float ballRadius;
    float ballAngle;

    bool mIsMovingLeft;
    bool mIsMovingRight;

    int v;

    Player _player[10];

};
