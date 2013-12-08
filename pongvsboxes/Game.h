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

private:
    World mWorld;

    void processEvents();
    void update(sf::Time TimePerFrame);
    void render();

    sf::RenderWindow mWindow;


};
