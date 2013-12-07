
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "ResourceIdentifier.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Block : public Entity
{
    public:
        // Default constructor
        Block(const TextureHolder& textures);
     //   Block(float x, float y, int life = 0);

        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


    protected:

        sf::Sprite mSprite;

};
