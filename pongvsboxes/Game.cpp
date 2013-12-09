//# include <SFML/Graphics.cp

#include "Game.h"
#include <cmath>
#include <vector>

const double PI  =3.141592653589793238462;
const sf::Time TimePerFrame = sf::seconds(1.f/60);

Game::Game()
: mWindow(sf::VideoMode(800, 600), "Pong vs Boxes", sf::Style::Fullscreen)
, mFont()
, mScore()
, mLevel()
, mLife()
{
    mWorld = new World(mWindow);

    mFont.loadFromFile("resources/sansation.ttf");
    mScore.setFont(mFont);
    mScore.setPosition(mWindow.getSize().x-100, mWindow.getSize().y-50);
    mScore.setCharacterSize(20);
    mScore.setColor(sf::Color::White);

    mLevel.setFont(mFont);
    mLevel.setPosition(25, mWindow.getSize().y-50);
    mLevel.setCharacterSize(20);
    mLevel.setColor(sf::Color::White);

    mLife.setFont(mFont);
    mLife.setPosition(25, mWindow.getSize().y-100);
    mLife.setCharacterSize(20);
    mLife.setColor(sf::Color::White);

    mCenterText.setFont(mFont);
    mCenterText.setPosition(400, 300);
    mCenterText.setCharacterSize(35);
    mCenterText.setColor(sf::Color::White);

    if (!(splashScreen.loadFromFile("resources/SplashScreen.png")))
    {
        return;
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
        if (mWorld->winGame)
            mCenterText.setString("You win!");
        else if(mWorld->loseGame)
            mCenterText.setString("Game over!");
        if (mWorld->exit)
        {
            gameStarted = false;
            delete mWorld;
            mWorld = new World(mWindow);
            mWorld->exit = false;
            mCenterText.setString("");

        }
        if (!gameStarted)
        {
            showSplashScreen();
        }

        timeSinceLastUpdate += clock.restart();
        while (timeSinceLastUpdate > TimePerFrame)
        {
            timeSinceLastUpdate -=TimePerFrame;
            processEvents();

            updateTexts();
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
            if (!gameStarted)
                gameStarted = true;
            if (mWorld->winGame || mWorld->loseGame)
                mWorld->exit = true;
            mWorld->setPause(false);
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

    mWorld->update(TimePerFrame);

}

void Game::render()
{
    mWindow.clear();

    //Ritar världen
	mWorld->draw();

    mWindow.draw(mScore);
    mWindow.draw(mLevel);
    mWindow.draw(mLife);
    mWindow.draw(mCenterText);
	mWindow.display();
}


void Game::handlePlayerInput(sf::Keyboard::Key key, bool pressed)
{
    if (key == sf::Keyboard::D)
        mWorld->mIsMovingRight = pressed;
    if (key == sf::Keyboard::A)
        mWorld->mIsMovingLeft = pressed;
    if (key == sf::Keyboard::Escape)
        mWindow.close();
}

void Game::updateTexts()
{
    mScore.setString("Score: " + mWorld->getScore());
    mLevel.setString("Level: " + mWorld->getLevel());
    mLife.setString("Life: " + mWorld->getLife());
}

void Game::showSplashScreen()
{
    sf::Sprite splash(splashScreen);

    mWindow.draw(splash);
    mWindow.display();

    while(mWindow.isOpen())
    {
        processEvents();
        if (gameStarted)
            return;
    }
}

