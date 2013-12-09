#include "Player.h"
#include "ResourceHolder.hpp"


#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/Sprite.hpp>


Player::Player(Type type, const TextureHolder& textures)
 : mType(type), mSprite(textures.get(Textures::Player))
{
    sf::FloatRect bounds = mSprite.getLocalBounds();
	mSprite.setOrigin(bounds.width / 2.f, bounds.height / 2.f);
}


void Player::drawCurrent(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.draw(mSprite, states);
}
sf::FloatRect Player::getBoundingRect() const
{
        return getWorldTransform().transformRect(mSprite.getGlobalBounds());
}
unsigned int Player::getCategory() const
{
      return Category::Player;
}

void Player::updateCurrent(sf::Time dt)
{
        move(getVelocity()* dt.asSeconds());
}
