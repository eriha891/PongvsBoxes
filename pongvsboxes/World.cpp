#include "World.hpp"
#include "Foreach.hpp"

#include <SFML/Graphics/RenderWindow.hpp>

#include <sstream>
#include <stdlib.h>



World::World(sf::RenderWindow& window)
: mWindow(window)
, mTextures()
, mSceneGraph()
, mSceneLayers()
, distribution(-1/(2*PI),1/(2*PI))
{
    ballAngle = PI/4;

    mIsMovingLeft = false;
    mIsMovingRight = false;


    for (int i=0; i<MAX_AMOUNT_OF_BLOCKS; i++)
    {
        mBlocks[i] = nullptr;
    }
	loadTextures();
	buildScene();


}

//Här laddar vi de texturer (bilder) vi behöver.
void World::loadTextures()
{
    mTextures.load(Textures::Block, "resources/block.png");
    mTextures.load(Textures::Player, "resources/player.png");
    mTextures.load(Textures::Ball, "resources/ball.gif");
}

//Funktionen som skapar hela "världen", i vårt fall alla blocks, player, och ball.
void World::buildScene()
{
    for (std::size_t i = 0; i <LayerCount; ++i)
    {
        SceneNode::Ptr layer(new SceneNode());
        mSceneLayers[i] = layer.get();

        mSceneGraph.attachChild(std::move(layer));
    }

    //Skapar tio block och lägger i Lagret Foreground


    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 12; j++){
            std::unique_ptr<Block> block(new Block(Block::Block1, mTextures));
            mBlocks[i] = block.get();
            mBlocks[i]->setPosition(100+75*j, 50 + 50*i);
            mBlocks[i]->setVelocity(0, 0);
            mSceneLayers[Foreground]->attachChild(std::move(block));
        }
    }

    //Skapar Player och sätter i foreground
    std::unique_ptr<Player> player(new Player(Player::Player1, mTextures));
    mPlayer = player.get();
    mPlayer->setPosition(500,700);
    mSceneLayers[Foreground]->attachChild(std::move(player));

    //Skapar en Ball och sätter i foreground
    std::unique_ptr<Ball> ball(new Ball(Ball::Ball1, mTextures));
    mBall = ball.get();
    mBall->setPosition(600, 600);
    mSceneLayers[Foreground]->attachChild(std::move(ball));


}

void World::draw()
{
    //Vi behöver inga views just nu
    //mWindow.setView(mWorldView);
    mWindow.draw(mSceneGraph);
}

void World::update(sf::Time dt)
{

    sf::Vector2f speed(0.f, 0.f);

    if(mIsMovingLeft)
            speed.x -= 200.f;
    if(mIsMovingRight)
            speed.x += 200.f;
    if (!(((mPlayer->getPosition().x - mPlayer->getBoundingRect().width/2) < 0 && speed.x < 0) ||
           (mPlayer->getPosition().x + mPlayer->getBoundingRect().width/2) > mWindow.getSize().x && speed.x > 0))
           mPlayer->move(speed * dt.asSeconds());

    if ((mBall->getPosition().y + mBall->getBoundingRect().height/2) > mWindow.getSize().y)
    {
        //HÄR SKA MAN DÖ EGENTLIGEN
        ballAngle = -ballAngle;
    }
    else if ((mBall->getPosition().y - mBall->getBoundingRect().height/2)  < 0)
    {
        randomValue = distribution(generator);
        ballAngle = -ballAngle + randomValue;
    }
    else if ((mBall->getPosition().x - mBall->getBoundingRect().width/2) < 0)
    {
        randomValue = distribution(generator);
        ballAngle = PI - ballAngle + randomValue;

    }
    else if ((mBall->getPosition().x + mBall->getBoundingRect().width/2) > mWindow.getSize().x)
    {
        //ballAngle = PI - ballAngle + v;
        randomValue = distribution(generator);
        ballAngle = PI - ballAngle + randomValue;
    }


    mBall->setVelocity(300 * std::cos(ballAngle), 300 * std::sin(ballAngle));

    handleCollisions();

    mSceneGraph.update(dt);
}

bool matchesCategories(SceneNode::Pair& colliders, Category::Type type1, Category::Type type2)
{
        unsigned int category1 = colliders.first->getCategory();
        unsigned int category2 = colliders.second->getCategory();

        // Make sure first pair entry has category type1 and second has type2
        if (type1 & category1 && type2 & category2)
        {
                return true;
        }
        else if (type1 & category2 && type2 & category1)
        {
                std::swap(colliders.first, colliders.second);
                return true;
        }
        else
        {
                return false;
        }
}

void World::handleCollisions()
{
        std::set<SceneNode::Pair> collisionPairs;
        mSceneGraph.checkSceneCollision(mSceneGraph, collisionPairs);

        FOREACH(SceneNode::Pair pair, collisionPairs)
        {
                if (matchesCategories(pair, Category::Ball, Category::Block))
                {
                        auto& ball = static_cast<Ball&>(*pair.first);
                        auto& block =  static_cast<Block&>(*pair.second);


                        block.move(1000, 0);
                        score += 10;
                        randomValue = distribution(generator);
                        ballAngle = -ballAngle + randomValue;
                }
                else if (matchesCategories(pair, Category::Ball, Category::Player))
                {
                        auto& ball = static_cast<Ball&>(*pair.first);
                        auto& player = static_cast<Player&>(*pair.second);

                        randomValue = distribution(generator);
                        ballAngle = -ballAngle + randomValue;
                }
}
}



void World::handlePlayerInput(sf::Keyboard::Key key, bool pressed)
{
    if (key == sf::Keyboard::D)
        mIsMovingRight = pressed;
    if (key == sf::Keyboard::A)
        mIsMovingLeft = pressed;
}

std::string World::getScore()
{
    std::stringstream stream;
    stream << score;
    return stream.str();
}
