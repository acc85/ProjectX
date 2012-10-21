#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile: public Sprite
{

    private:
        Vector2f direction;
        Vector2f location;
        float radianRotation;

    public:
        static Texture projTexture;
        Projectile();
        float getRadianRotation();
        void setRadianRotation(float rad);
        Vector2f getLocation();
        void setLocation(Vector2f loc);

};

#endif // PROJECTILE_H_INCLUDED
