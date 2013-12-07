#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include <iostream>

#include "player.h"
#include "ball.h"
#include "block.h"

class Game
{
public:

    sf::RenderWindow mWindow;
    //sf::RectangleShape mPlayer;
    //sf::CircleShape mBall;
    //sf::RectangleShape testBlock;
    Player _player;
    /*
    int blockLife;

    float ballRadius;
    float ballAngle;

    bool mIsMovingLeft;
    bool mIsMovingRight;

    int v;

    Player _player[10];
    */

    Game();

    void run();
    void handlePlayerInput(sf::Keyboard::Key, bool pressed);
//private:
    void processEvents();
    void update(sf::Time TimePerFrame);
    void render();
};
