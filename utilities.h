#ifndef UTILITIES_H_INCLUDED
#define UTILITIES_H_INCLUDED
#include <SFML/Graphics.hpp>
#include <string>
#include <iostream>



using namespace std;

class utilities
{
    public:
        void printVector2f(sf::Vector2f v);
        void printf(string s = NULL);
        void printFl(string s,float f = 0);
        void printFl(float f = 0);

};



#endif // UTILITIES_H_INCLUDED
