#ifndef CHARACTER_H_INCLUDED
#define CHARACTER_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

class Character: public RectangleShape
{
    private:
        int health;


    public:
        Character(int h);
        Character(Vector2f size);
        ~Character();
        void setHealth(int h);
        int getHealth();
        void createFunnel();
        //RectangleShape funnel;
        Texture wheelTexture;
        Texture funnelTexture;
        //CircleShape Wheel1;
        //CircleShape Wheel2;
        Sprite Wheel1;
        Sprite Wheel2;
        Sprite funnel;
        void moveCharacter(const Vector2f& offset);
        void rotateFunnel(float angle);
        void rotateWheelsLeft();
        void rotateWheelsRight();
};
#endif // CHARACTER_H_INCLUDED
