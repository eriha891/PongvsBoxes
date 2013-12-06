//# include <SFML/Graphics.cp

#include "Game.h"
#include <cmath>

const double PI  =3.141592653589793238462;

Game::Game()
: mWindow(sf::VideoMode(1024, 768), "Pong vs Boxes")
, mPlayer(), mBall()
{
    mIsMovingLeft = false;
    mIsMovingRight = false;
    mPlayer.setSize(sf::Vector2f(100.f, 10.f));
    mPlayer.setPosition(mWindow.getSize().x/2, mWindow.getSize().y - mWindow.getSize().y/10);
    mPlayer.setFillColor(sf::Color::Cyan);

    ballRadius = 20.f;
    mBall.setRadius(ballRadius);
    mBall.setOrigin(ballRadius,ballRadius);
    mBall.setPosition(400.f, 400.f);
    mBall.setFillColor(sf::Color::Red);

    ballAngle = -PI/4;

   //skapar tv� rader av block
    for(int i = 0; i < 10; i++){
       if( i > 4 ){
           int x = i%5;
           _player[i].setSize(sf::Vector2f(150.f,25.f));
           _player[i].setPosition(30.f +x*200.f, 0.f + 50.f);
           _player[i].setFillColor(sf::Color::Green);

       }else{
           _player[i].setSize(sf::Vector2f(150.f,25.f));
           _player[i].setPosition(30.f +i*200.f, 0.f);
           _player[i].setFillColor(sf::Color::Green);

       }
    }
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
    sf::Vector2f speed(0.f, 0.f);
    if(mIsMovingLeft)
            speed.x -= 200.f;
    if(mIsMovingRight)
            speed.x += 200.f;
    if (!((mPlayer.getPosition().x < 0 && speed.x < 0) ||
           mPlayer.getPosition().x +100 > mWindow.getSize().x && speed.x > 0))
            mPlayer.move(speed * TimePerFrame.asSeconds());

    //Randfunktion som bidrar med en "slumpm�ssig" viknel efter krock.
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

    if (mBall.getPosition().x + ballRadius > testBlock.getPosition().x &&
        mBall.getPosition().x - ballRadius < testBlock.getPosition().x + 150 &&
        mBall.getPosition().y + ballRadius > testBlock.getPosition().y &&
        mBall.getPosition().y - ballRadius < testBlock.getPosition().y + 25)
    {
        ballAngle = -ballAngle;
        testBlock.move(1000, 0);
    }

    //tar bort block vid kollision
    for (int i = 0 ; i < 10 ; i++){
       if (mBall.getPosition().x + ballRadius > _player[i].getPosition().x &&
           mBall.getPosition().x - ballRadius < _player[i].getPosition().x + 150 &&
           mBall.getPosition().y + ballRadius > _player[i].getPosition().y &&
           mBall.getPosition().y - ballRadius < _player[i].getPosition().y + 25)
       {
           ballAngle = -ballAngle;
           _player[i].move(1000, 0);
       }
    }

    mBall.move(TimePerFrame.asSeconds() * 200 * std::cos(ballAngle),
               TimePerFrame.asSeconds() * 200 * std::sin(ballAngle));


}

void Game::render()
{
    mWindow.clear();
    mWindow.draw(mPlayer);
    mWindow.draw(mBall);

    for (int i = 0; i < 10; i++){
    //_player[i].Draw(mWindow);
      mWindow.draw(_player[i]);
    }

    //mWindow.draw(testBlock);
    mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed)
{
    if (key == sf::Keyboard::D)
        mIsMovingRight = pressed;
    if (key == sf::Keyboard::A)
        mIsMovingLeft = pressed;
}


