#ifndef BALL_H
#define BALL_H

#include "Entity.h"
#include "ResourceIdentifier.hpp"

#include <String>
#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Sprite.hpp>

class Ball : public Entity
{
public:
   enum Type
                {
                  Ball1

                };


     Ball(Type type, const TextureHolder& textures);

     virtual unsigned int        getCategory() const;

     virtual sf::FloatRect       getBoundingRect() const;

     virtual void drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const;


protected:

    sf::Sprite mSprite;

private:
   Type mType;
};

#endif
