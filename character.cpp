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
    funnel.setSize(Vector2f(100,10));
    funnel.setPosition(getPosition().x+50,getPosition().y+50);
    funnel.setFillColor(Color::Red);
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

void Character::moveCharacter(const Vector2f& offset)
{
    move(offset);
    funnel.move(offset);
};

void Character::rotateFunnel(float angle)
{
    funnel.rotate(angle);
}

