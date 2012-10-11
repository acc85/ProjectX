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

    wheelTexture.loadFromFile("Wheel.png");

    Wheel1.setTexture(wheelTexture);
    Wheel2.setTexture(wheelTexture);

    Wheel1.setScale(2,2);
    Wheel2.setScale(2,2);

    Wheel1.setOrigin(wheelTexture.getSize().x/2, wheelTexture.getSize().y/2);
    Wheel2.setOrigin(wheelTexture.getSize().x/2, wheelTexture.getSize().y/2);
    Wheel1.setPosition(10,size.y-wheelTexture.getSize().y);
    Wheel2.setPosition(90,size.y-wheelTexture.getSize().y);
//    Wheel1.setFillColor(Color::White);
//    Wheel2.setFillColor(Color::White);
//    Wheel1.setRadius(30);
//    Wheel2.setRadius(30);
//    Wheel1.setPosition(10,size.y-Wheel2.getRadius());
//    Wheel2.setPosition(90,size.y-Wheel1.getRadius());
//    Wheel1.setOrigin(Wheel1.getRadius(), Wheel1.getRadius());
//    Wheel2.setOrigin(Wheel2.getRadius(), Wheel2.getRadius());
    funnel.setSize(Vector2f(100,10));
    funnel.setPosition(getPosition().x+(getSize().x/2),getPosition().y+(getSize().y/2));
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
    Wheel1.move(offset);
    Wheel2.move(offset);
};

void Character::rotateWheelsLeft()
{
    Wheel1.rotate(-0.1);
    Wheel2.rotate(-0.1);
};


void Character::rotateWheelsRight()
{
    Wheel1.rotate(0.1);
    Wheel2.rotate(0.1);
};

void Character::rotateFunnel(float angle)
{
    funnel.rotate(angle);
};

