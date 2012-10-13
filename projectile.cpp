#include "projectile.h"
using namespace sf;

Projectile::Projectile()
{
    setPosition(100,100);
    static Texture texture;
    texture.loadFromFile("bullet.png");
    setTexture(texture);
    setScale(0.5,0.5);
    setOrigin(texture.getSize().x/2, texture.getSize().y/2);


}

Vector2f Projectile::getDirection()
{
    return direction;
}

void Projectile::setDirection(Vector2f dir)
{
    direction = dir;
}

Vector2f Projectile::getLocation()
{
    return location;
}

void Projectile::setLocation(Vector2f loc)
{
    location = loc;
}

