// Copyright [2021] Peter Nguyen
/*
Peter Nguyen
Last Updated: 10/18/21
TFractal.cpp: A program that uses the Triangle class and a recursive
              function to create a variation of a Sierpinski triangle.
              The program takes in two command line arguments, a
              double length and int iteration that it uses to display
              the Sierpinski triangle to a SFML window. The program 
              abides by Google's style guide.      
*/
#include <string>
#include <cmath>
#include "Triangle.h"


// Recursive function declaration
void fTree(Triangle s, int i, sf::RenderWindow& window); //NOLINT

int main(int argc, char** argv) {
    // Get length and number of iterations from command line
    double length = std::stod(argv[1]);
    int iter = std::stoi(argv[2]);

    // Make window based on length of base triangle
    sf::RenderWindow window(sf::VideoMode(length*3, length*3), "Triangles");
    sf::Vector2u winSize = window.getSize();

    window.clear(sf::Color::White);

    // Create base triangle and position it depending on window size
    sf::Vector2f initial;
    initial.x = winSize.x/4;
    initial.y = winSize.y/3;
    Triangle base(length, initial);

    // SFML window loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
        window.close();
        }
        window.clear(sf::Color::White);
        window.draw(base);
        fTree(base, iter, window);
        window.display();
    }
}

// Recursive function that takes in a starting triangle, the number of
// iterations, and a window reference
// Creates three triangles and draws them around the base triangle and
// recrusively calls itself for each triangle created
// until the number of iterations has been reached
void fTree(Triangle s, int i, sf::RenderWindow& window) { // NOLINT
    // If base case is 0 return
    if (i == 0) return;

    // Vector2f to get position of initial point for the next triangle
    sf::Vector2f next = s.getPt1();
    // First triangle
    next.x -= (s.getLength()/4);
    next.y -= ((sqrt(3)/2)*(s.getLength()/2));
    Triangle a((s.getLength()/2), next);
    window.draw(a);
    // Second triangle
    next = s.getPt2();
    Triangle b((s.getLength()/2), next);
    window.draw(b);
    next = s.getPt3();
    next.x = s.getPt1().x;
    // Third triangle
    Triangle c((s.getLength()/2), next);
    window.draw(c);

    // Decrement iteration count
    i--;

    // Return if iteration count has been reached
    if (i == 0) return;

    // Recursively call for each new triangle
    fTree(a, i, window);
    fTree(b, i, window);
    fTree(c, i, window);
}
