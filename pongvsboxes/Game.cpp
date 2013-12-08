//# include <SFML/Graphics.cp

#include "Game.h"
#include <cmath>
#include <vector>

const double PI  =3.141592653589793238462;
const sf::Time TimePerFrame = sf::seconds(1.f/60);

Game::Game()
: mWindow(sf::VideoMode(1024, 768), "Pong vs Boxes", sf::Style::Close)
, mBall()
, mWorld(mWindow)
{
//    mIsMovingLeft = false;
//    mIsMovingRight = false;
    mPlayer.setSize(sf::Vector2f(100.f, 10.f));
    mPlayer.setPosition(mWindow.getSize().x/2, mWindow.getSize().y - mWindow.getSize().y/10);
    mPlayer.setFillColor(sf::Color::Cyan);

    ballRadius = 20.f;
    mBall.setRadius(ballRadius);
    mBall.setOrigin(ballRadius,ballRadius);
    mBall.setPosition(400.f, 400.f);
    mBall.setFillColor(sf::Color::Red);

    ballAngle = -PI/4;

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
    //Update Player depending on keypresses

//    sf::Vector2f speed(0.f, 0.f);
//    if(mIsMovingLeft)
//            speed.x -= 200.f;
//    if(mIsMovingRight)
//            speed.x += 200.f;
//    if (!((mPlayer.getPosition().x < 0 && speed.x < 0) ||
//           mPlayer.getPosition().x +100 > mWindow.getSize().x && speed.x > 0))
//            mPlayer.move(speed * TimePerFrame.asSeconds());


    //Randfunktion som bidrar med en "slumpmässig" viknel efter krock.
    //v = rand() % -10 + 10;
    //Update ball
    //Collision check against screen edge
    if (mBall.getPosition().y + ballRadius > mWindow.getSize().y)
    {
        //ballAngle = -ballAngle + v;
        ballAngle = -ballAngle;
    }
    if (mBall.getPosition().y - ballRadius < 0)
    {
        //ballAngle = -ballAngle + v;
        ballAngle = -ballAngle;
    }
    if (mBall.getPosition().x - ballRadius < 0)
    {
        //ballAngle = PI - ballAngle + v;
        ballAngle = PI - ballAngle;
    }
    if (mBall.getPosition().x + ballRadius > mWindow.getSize().x)
    {
        //ballAngle = PI - ballAngle + v;
        ballAngle = PI - ballAngle;
    }

    //Collision check against Player
    if (mBall.getPosition().x + ballRadius > mPlayer.getPosition().x &&
        mBall.getPosition().x - ballRadius < mPlayer.getPosition().x + 100 &&
        mBall.getPosition().y + ballRadius > mPlayer.getPosition().y &&
        mBall.getPosition().y - ballRadius < mPlayer.getPosition().y + 10)
    {
        ballAngle = -ballAngle;
    }
/*
    if (mBall.getPosition().x + ballRadius > testBlock.getPosition().x &&
        mBall.getPosition().x - ballRadius < testBlock.getPosition().x + 150 &&
        mBall.getPosition().y + ballRadius > testBlock.getPosition().y &&
        mBall.getPosition().y - ballRadius < testBlock.getPosition().y + 25)
    {
        ballAngle = -ballAngle;
        testBlock.move(1000, 0);
    } */

    //tar bort block vid kollision
    /*
    for (int i = 0 ; i < 10 ; i++){
       if (mBall.getPosition().x + ballRadius > _player[i].getPosition().x &&
           mBall.getPosition().x - ballRadius < _player[i].getPosition().x + 150 &&
           mBall.getPosition().y + ballRadius > _player[i].getPosition().y &&
           mBall.getPosition().y - ballRadius < _player[i].getPosition().y + 25)
       {
           ballAngle = -ballAngle;
           _player[i].move(1000, 0);
       }
    }*/

    mBall.move(TimePerFrame.asSeconds() * 200 * std::cos(ballAngle),
               TimePerFrame.asSeconds() * 200 * std::sin(ballAngle));

    mWorld.update(TimePerFrame);

}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.draw(mBall);

    for (int i = 0; i < 10; i++){
    //_player[i].Draw(mWindow);
      //mWindow.draw(_player[i]);
    }

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


