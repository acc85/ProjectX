#include "character.h"

Character::Character(int h)
{
    setHealth(h);
};

Character::Character(Vector2f size)
{
    setHealth(100);
    setFillColor(Color::Red);
    setSize(Vector2f(100.f,100.f));
    setPosition(0,size.y-getSize().y);
};

Character::~Character()
{

}


int Character::getHealth()
{
    return health;
};

void Character::setHealth(int h)
{
    health = h;
};
