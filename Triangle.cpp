// Copyright [2021] Peter Nguyen
/*
Peter Nguyen
Last Updated: 10/18/21
Triangle.h: An implementation file for the Triangle class.
            It stores 3 points of a triangle and overrides
            the draw function from Drawable.
*/
#include <cmath>
#include "Triangle.h"

// Default constructor
Triangle::Triangle() {}

// Constructor that creates a triangle from a starting point
// and length
Triangle::Triangle(double l, sf::Vector2f init) {
    length = l;
    pt1 = init;
    pt2.x = pt1.x+length;
    pt2.y = pt1.y;
    pt3.x = pt1.x+(length/2);
    pt3.y = pt1.y+((sqrt(3)/2)*length);
}

// Override draw to make drawable
// Uses ConvexShape to draw a triangle with 3 points
void Triangle::draw(sf::RenderTarget &target, sf::RenderStates states) const {
    sf::ConvexShape triangle;
    triangle.setPointCount(3);
    triangle.setPoint(0, pt1);
    triangle.setPoint(1, pt2);
    triangle.setPoint(2, pt3);
    // Colorize the outline and fill colors
    triangle.setOutlineColor(sf::Color::Red);
    triangle.setFillColor(sf::Color::Black);
    triangle.setOutlineThickness(1);
    // draw ConvexShape onto window
    target.draw(triangle);
}
