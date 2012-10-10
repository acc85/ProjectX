#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include "character.cpp"
#define PI 3.14159265
using namespace sf;


int main()
{
    int mousecount = 0;
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
                character.rotateFunnel(-0.1);
            }
        }
        if(Keyboard::isKeyPressed((Keyboard::Down)))
        {
            if(character.funnel.getRotation() < 50)
            {
                 character.rotateFunnel(0.1);
            }
        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {
            if(mousecount == 0)
            {
                float realY = window.getSize().y;
                float deltaY = (Mouse::getPosition(window).y - character.funnel.getPosition().y);
				float deltaX = (Mouse::getPosition(window).x - character.funnel.getPosition().x);
				Vector2f shootVector = Vector2f(deltaX,deltaY);
				float shootAngleRadians= (atanf(deltaY/deltaX));
				float shootAngleDegrees= (shootAngleRadians*(180/PI));
				float diff =  shootAngleDegrees*-1;
                std::cout<<"shootDegrees: "<<diff<<std::endl;
                std::cout<<"MouseY: "<<Mouse::getPosition(window).y<<std::endl;
                mousecount = 1;
            }
        }
        else
        {
            mousecount = 0;
        }
        window.clear();
        window.draw(background);
        window.draw(character);
        window.draw(character.funnel);
        window.display();
    }

    return 0;
}
