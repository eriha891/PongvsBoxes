//# include <SFML/Graphics.cp

#include "Game.h"

Game::Game()
: mWindow(sf::VideoMode(640, 480), "Pong vs Boxes")
, mPlayer()
{
    mIsMovingLeft = false;
    mIsMovingRight = false;
    mPlayer.setRadius(40.f);
    mPlayer.setPosition(100.f, 100.f);
    mPlayer.setFillColor(sf::Color::Cyan);
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
    sf::Vector2f speed(0.f, 0.f);
    if(mIsMovingLeft)
            speed.x -= 100.f;
    if(mIsMovingRight)
            speed.x += 100.f;

    mPlayer.move(speed * TimePerFrame.asSeconds());
}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed)
{

    if (key == sf::Keyboard::D)
        mIsMovingRight = pressed;
    if (key == sf::Keyboard::A)
        mIsMovingLeft = pressed;
}
