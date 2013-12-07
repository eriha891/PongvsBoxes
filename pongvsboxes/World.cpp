#include "World.hpp"

#include <SFML/Graphics/RenderWindow.hpp>


World::World(sf::RenderWindow& window)
: mWindow(window)
, mTextures()
, mSceneGraph()
, mSceneLayers()
{
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
    mTextures.load(Textures::Ball, "resources/ball.png");
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
    for (int i = 0; i < 10; i++)
    {
        std::unique_ptr<Block> block(new Block(mTextures));
        mBlocks[i] = block.get();
        mBlocks[i]->setPosition(100+75*i, 100);
        mBlocks[i]->setVelocity(0, 0);
        mSceneLayers[Foreground]->attachChild(std::move(block));

    }

    //Skapar Player och sätter i foreground
    std::unique_ptr<Player> player(new Player(mTextures));
    mPlayer = player.get();
    mPlayer->setPosition(500, 500);
    mSceneLayers[Foreground]->attachChild(std::move(player));


    //Skapar en Ball och sätter i foreground
    std::unique_ptr<Ball> ball(new Ball(mTextures));
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
    mSceneGraph.update(dt);
}
