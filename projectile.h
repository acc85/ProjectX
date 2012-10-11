#ifndef PROJECTILE_H_INCLUDED
#define PROJECTILE_H_INCLUDED
#include <SFML/Graphics.hpp>
using namespace sf;

class Projectile: public Sprite
{

    private:
        Vector2f location;

    public:
        static Texture projTexture;
        Projectile();
        Vector2f getLocation();
        void setLocation(Vector2f loc);

};

#endif // PROJECTILE_H_INCLUDED
