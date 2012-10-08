#include <SFML/Graphics.hpp>
#include <iostream>
#include "character.cpp"
using namespace sf;


int main()
{
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    Character character(Vector2f(window.getSize()));
    Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("MapTexture.png"))
         return EXIT_FAILURE;
    backgroundTexture.loadFromFile("MapTexture.png");
    Sprite background(backgroundTexture);
    background.setPosition(0, 0);

    //pointer object
    //Character *newchar  = new Character(Vector2f(window.getSize()));
    //std::cout<<"size is: "<<&newchar->getSize().x<<std::endl;
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
            {
                if(background.getPosition().x >= 0)
                {
                    character.moveCharacter(Vector2f(-0.1,0));
                }
                else if(background.getPosition().x <= ((backgroundTexture.getSize().x-window.getSize().x)*-1.0f))
                {
                    if (character.getPosition().x >= window.getSize().x/2-character.getSize().x)
                        character.moveCharacter(Vector2f(-0.1,0));
                    else
                    {
                        background.move(Vector2f(0.1,0));
                    }
                }
                else
                {
                    background.move(Vector2f(0.1,0));
                }
            }
        }

        if(Keyboard::isKeyPressed((Keyboard::Right)))
        {
            std::cout<<"background x is: "<<background.getPosition().x<<std::endl;
            if (character.getPosition().x <= window.getSize().x/2-character.getSize().x)
            {
                character.moveCharacter(Vector2f(0.1,0));
            }
            else if(background.getPosition().x <= ((backgroundTexture.getSize().x-window.getSize().x)*-1.0f))
            {
                if (character.getPosition().x < window.getSize().x-character.getSize().x)
                    character.moveCharacter(Vector2f(0.1,0));
            }
            else
            {
                background.move(Vector2f(-0.1,0));
            }
        }
        if(Keyboard::isKeyPressed((Keyboard::Up)))
        {
            if(character.funnel.getRotation() > -50)
            {
                 std::cout<<"the angle is: "<<character.funnel.getRotation()<<std::endl;
                 character.rotateFunnel(-0.1);
            }
        }
        if(Keyboard::isKeyPressed((Keyboard::Down)))
        {
            if(character.funnel.getRotation() < 50)
            {
                 std::cout<<"the angle is: "<<character.funnel.getRotation()<<std::endl;
                 character.rotateFunnel(0.1);
            }
        }
        window.clear();
        window.draw(background);
        window.draw(character);
        window.draw(character.funnel);
        window.display();
    }

    return 0;
}
