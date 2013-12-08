#ifndef ENTITY_H
#define ENTITY_H

#include "SceneNode.hpp"

class Entity : public SceneNode
{
    public:
        void setVelocity(sf::Vector2f velocity);
        void setVelocity(float vx, float vy);

        sf::Vector2f getVelocity() const;

        void destroy();



    private:
        virtual void updateCurrent(sf::Time dt);

        sf::Vector2f mVelocity;


};



#endif
