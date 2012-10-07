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
        RectangleShape funnel;
        void moveCharacter(const Vector2f& offset);
        void rotateFunnel(float angle);

};
#endif // CHARACTER_H_INCLUDED
