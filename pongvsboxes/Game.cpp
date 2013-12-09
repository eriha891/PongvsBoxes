//# include <SFML/Graphics.cp

#include "Game.h"
#include <cmath>
#include <vector>

const double PI  =3.141592653589793238462;
const sf::Time TimePerFrame = sf::seconds(1.f/60);

Game::Game()
: mWindow(sf::VideoMode(1024, 768), "Pong vs Boxes", sf::Style::Close)
, mWorld(mWindow)
{

}

void Game::run()
{
    //Set fps to 60 fps
    const sf::Time TimePerFrame = sf::seconds(1.f/60);

    //Game loop with clock
    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    while(mWindow.isOpen())
    {
        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -=TimePerFrame;
            processEvents();
            update(TimePerFrame);
        }
        render();
    }
}

//Function that processes events
void Game::processEvents()
{
    sf::Event event;

    while (mWindow.pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::KeyPressed:
            handlePlayerInput(event.key.code, true);
            break;
        case sf::Event::KeyReleased:
            handlePlayerInput(event.key.code, false);
            break;
        case sf::Event::Closed:
            mWindow.close();
            break;
        }
    }
}

void Game::update(sf::Time TimePerFrame)
{
    mWorld.update(TimePerFrame);
}

void Game::render()
{
    mWindow.clear();

    //Ritar världen
	mWorld.draw();

	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed)
{
    if (key == sf::Keyboard::D)
        mWorld.mIsMovingRight = pressed;
    if (key == sf::Keyboard::A)
        mWorld.mIsMovingLeft = pressed;
}


