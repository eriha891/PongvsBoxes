
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include "Entity.h"
#include "ResourceIdentifier.hpp"
#include <SFML/Graphics/Sprite.hpp>

class Block : public Entity
{
    public:
       enum Type
                {
                  Block1
                };


        Block(Type type, const TextureHolder& textures);


        // Default constructor

        //   Block(float x, float y, int life = 0);

        virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

        virtual unsigned int        getCategory() const;
        virtual sf::FloatRect getBoundingRect() const;


    protected:

        sf::Sprite mSprite;
    private:
        Type mType;

};
