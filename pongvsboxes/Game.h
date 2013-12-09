#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

#include "Player.h"
#include "World.hpp"
#include <vector>
class Game
{
public:
    Game();

    void run();

    void handlePlayerInput(sf::Keyboard::Key, bool pressed);

    void showSplashScreen();

private:
    World *mWorld;

    void processEvents();
    void update(sf::Time TimePerFrame);
    void render();
    void updateTexts();

    sf::RenderWindow mWindow;
    sf::Font mFont;
    sf::Text mScore;

    sf::Text mLevel;
    sf::Text mLife;
    sf::Text mCenterText;

    sf::Texture splashScreen;

    bool gameStarted = false;

};
