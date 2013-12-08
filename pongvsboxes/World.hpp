#ifndef WORLD_HPP
#define WORLD_HPP

#include "ResourceHolder.hpp"
#include "ResourceIdentifier.hpp"
#include "SceneNode.hpp"
//#include <Book/SpriteNode.hpp>

#include "Block.h"
#include "Player.h"
#include "Ball.h"

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics/View.hpp>
#include <SFML/Graphics/Texture.hpp>

#include <array>

const int MAX_AMOUNT_OF_BLOCKS = 100;

class World : private sf::NonCopyable
{
    public:
        explicit World(sf::RenderWindow& window);
        void update(sf::Time dt);
        void draw();
        void handlePlayerInput(sf::Keyboard::Key, bool pressed);

        bool mIsMovingLeft;
        bool mIsMovingRight;

    private:
        void loadTextures();
        void buildScene();

    private:
        enum Layer
        {
            Background,
            Foreground,
            LayerCount
        };

    private:

        void   handleCollisions();

        sf::RenderWindow& mWindow;
        TextureHolder mTextures;
        SceneNode mSceneGraph;
        std::array<SceneNode*, LayerCount> mSceneLayers;

        sf::FloatRect mWorldBounds;
        sf::Vector2f mSpawnPosition;

        Block* mBlocks[MAX_AMOUNT_OF_BLOCKS];
        Player* mPlayer;
        Ball* mBall;

        float ballAngle;
        const double PI  =3.141592653589793238462;


};

#endif
