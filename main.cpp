#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.cpp"
using namespace sf;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    Character character(Vector2f(window.getSize()));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
            {
                if (character.getPosition().x >= 0.f)
                    character.move(Vector2f(-0.1,0));
            }
        if(Keyboard::isKeyPressed((Keyboard::Right)))
        {
            if (character.getPosition().x < window.getSize().x-character.getSize().x)
                character.move(Vector2f(0.1,0));
        }

        window.clear();
        window.draw(character);
        window.display();
    }

    return 0;
}
