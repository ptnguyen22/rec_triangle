// Copyright [2021] Peter Nguyen
/*
Peter Nguyen
Last Updated: 10/18/21
Triangle.h: A header file for the Triangle class that
            represents a triangle and is drawable.    
*/
#ifndef TRIANGLE_H // NOLINT
#define TRIANGLE_H // NOLINT

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class Triangle: public sf::Drawable {
 public:
    // Constructors
    Triangle();
    Triangle(double l, sf::Vector2f init);

    // Override draw function
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;// NOLINT

    // Accessor functions
    sf::Vector2f getPt1() {return pt1;}
    sf::Vector2f getPt2() {return pt2;}
    sf::Vector2f getPt3() {return pt3;}
    double getLength() {return length;}

 private:
    double length;
    sf::Vector2f pt1, pt2, pt3;
};
#endif //NOLINT
