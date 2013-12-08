#ifndef PLAYER_H
#define PLAYER_H

#include "Entity.h"
#include "ResourceIdentifier.hpp"

#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Player : public Entity
{
public:
    enum Type
                {
                  Player1

                };
     Player(Type type, const TextureHolder& textures);

     virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;

     virtual unsigned int        getCategory() const;
     virtual sf::FloatRect       getBoundingRect() const;


protected:

    sf::Sprite mSprite;

private:
    Type mType;
};

#endif
