#include <SFML/Graphics.hpp>
#include <iostream>
#include <math.h>
#include <time.h>
#include "character.cpp"
#include "projectile.h"
#include "utilities.h"
#include <vector>
#define PI 3.14159265
//using namespace sf;


int main()
{
    utilities u;
    std::vector<Projectile> Projectiles;
    int funnelMove = 0;
    float moveRotation;
    Clock clock;
    int mousecount = 0;
    sf::RenderWindow window(sf::VideoMode(1024, 768), "SFML works!");
    Character character(Vector2f(window.getSize()));


    //Set Texture variables
    Texture backgroundTexture;
    Texture targetTexture;
    Texture projectileTexture;

    //Set Floor Variable
    RectangleShape floor;

    //Check to see if Texture image files exist. If not then set game to close
    if (!backgroundTexture.loadFromFile("MapTexture.png") || !targetTexture.loadFromFile("target.png") || !projectileTexture.loadFromFile("bullet.png"))
         return EXIT_FAILURE;

    //Assign Texture Variables png images
    backgroundTexture.loadFromFile("MapTexture.png");
    targetTexture.loadFromFile("target.png");
    projectileTexture.loadFromFile("bullet.png");

    //Create sprites with the texture variables
    Sprite background(backgroundTexture);
    Sprite target(targetTexture);


    //Set Size. colour and location of floor on map
    floor.setSize(Vector2f(backgroundTexture.getSize().x, 10));
    floor.setPosition(0,window.getSize().y-floor.getSize().y);
    floor.setFillColor(Color::Green);

    //Set Position of the background on map;
    background.setPosition(0, 0);

    Projectile proj;
    //proj.setPosition(100,100);


    //pointer object
    //Character *newchar  = new Character(Vector2f(window.getSize()));
    //std::cout<<"size is: "<<&newchar->getSize().x<<std::endl;


    while (window.isOpen())
    {

        Time time =  clock.getElapsedTime();
        sf::Event event;
        while (window.pollEvent(event))
        {
            //Check event in game window. If window is closed, then tell game window is closed. If mouse is moved, then move
            //target sprite to mouse position;
            if (event.type == sf::Event::Closed)
                window.close();
            else if (event.type == Event::MouseMoved)
            {
                target.setPosition(Mouse::getPosition(window).x-targetTexture.getSize().x/2, Mouse::getPosition(window).y-targetTexture.getSize().y/2);
            }

        }

        //Check to see if funnelMove variable is 1, this is set when a mouse left click is detected, and checks to see the mouse click
        //is infront of the player.. thus removing the possiblity of the funnel rotating behind or above the player


        if(funnelMove == 1 && Mouse::getPosition(window).x > character.getPosition().x)
        {
            //checks to see the rotation is either less than -50 or greater than 50. This is placed first on the if list to make sure
            //the game engine checks to see if the cursor is out of position for rotating funnel.
            if(moveRotation <= -50 || moveRotation >= 50)
            {
                if(character.funnel.getRotation() > -50)
                    character.rotateFunnel(-0.1);
                else
                    funnelMove = 0;
            }
            else if(moveRotation < 0)
            {
                if(character.funnel.getRotation() > moveRotation)
                    character.rotateFunnel(-0.1);
                else if(character.funnel.getRotation() < moveRotation)
                    character.rotateFunnel(0.1);
                else
                    funnelMove = 0;
            }
            else if(moveRotation > 0 )
            {
                if(character.funnel.getRotation() < moveRotation)
                    character.rotateFunnel(0.1);
                else
                    funnelMove = 0;
            }

        }

        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            if (character.getPosition().x >= 0.f)
            {
                character.rotateWheelsLeft();
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
                character.rotateWheelsRight();
                character.moveCharacter(Vector2f(0.1,0));
            }
            else if(background.getPosition().x <= ((backgroundTexture.getSize().x-window.getSize().x)*-1.0f))
            {
                if (character.getPosition().x < window.getSize().x-character.getSize().x)
                {
                    character.rotateWheelsRight();
                    character.moveCharacter(Vector2f(0.1,0));
                }
            }
            else
            {
                character.rotateWheelsRight();
                background.move(Vector2f(-0.1,0));
            }
        }
        if(Mouse::isButtonPressed(Mouse::Left))
        {

            if(mousecount == 0)
            {
                float deltaY = ( Mouse::getPosition(window).y - character.funnel.getPosition().y);
				float deltaX = ( Mouse::getPosition(window).x - character.funnel.getPosition().x);

				Vector2f shootVector = Vector2f(deltaX,deltaY);
				double length = sqrt((deltaX*deltaX)+(deltaY*deltaY));
                float normalX = deltaX/length;
                float normalY = (deltaY/length);
                float characterPosX = character.funnel.getPosition().x;
                float characterPosY = character.funnel.getPosition().y;
                float overShotVectorX = normalX*window.getSize().x;
                float overShotVectorY = normalY*window.getSize().y;
                Vector2f offScreenPoint= Vector2f(character.funnel.getPosition().x+overShotVectorX, character.funnel.getPosition().y+overShotVectorY);
				float shootAngleRadians= (atanf(deltaY/deltaX));
				float shootAngleDegrees= (shootAngleRadians*(180/PI));
				moveRotation = shootAngleDegrees;
				float diff =  shootAngleDegrees;
				if(diff >= -50 && diff<= 50 && Mouse::getPosition(window).x > character.getPosition().x)
				{
				    funnelMove = 1;
                    proj.setRadianRotation(shootAngleRadians);
                    proj.setPosition(characterPosX,characterPosY);
                    proj.setLocation(offScreenPoint);
                    proj.setRotation(moveRotation);
                    Projectiles.push_back(proj);
				}
                mousecount = 1;
            }
        }
        else
        {
            mousecount = 0;
        }



        window.setMouseCursorVisible(false);
        window.clear();
        window.draw(background);

        if(Projectiles.size() > 0)
        {
            for(int p=0 ; p<Projectiles.size(); p++)
            {
                if(Projectiles.at(p).getPosition() != Projectiles.at(p).getLocation())
                {
                    Time elapsed = clock.getElapsedTime();
                    window.draw(Projectiles.at(p));
                    Projectiles.at(p).setPosition(Projectiles.at(p).getPosition().x+cos(Projectiles.at(p).getRadianRotation())*0.4, Projectiles.at(p).getPosition().y+sin(Projectiles.at(p).getRadianRotation())*0.4);
                }
            }

        }

        window.draw(character);
        window.draw(character.funnel);
        window.draw(floor);
        window.draw(character.Wheel1);
        window.draw(character.Wheel2);
        window.draw(target);

        window.display();
    }

    return 0;
}
