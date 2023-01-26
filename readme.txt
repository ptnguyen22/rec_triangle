**********************************************************************
 *  Recursive Graphics (Triangle Fractal/Sierpinski triangle)                       
 **********************************************************************

Peter Nguyen

Developed in Ubuntu using the G++ GNU compiler.
Dependencies: SFML --to install: sudo apt-get install libsfml-dev

**********************************************************************

This program uses SFML to display a variation on the Sierpinkski triangle. The program takes two command line arguments to get the length for the base triangle and an integer for the number of iterations to create. To do this, there is a drawable Triangle class that holds 3 Vector2f for each point in the triangle. The draw function uses ConvexShape and the three points to draw a triangle on the specified coordinates. There is a recursive function that main uses to draw triangles based on the iterations and base triangle. All files included have been run through cpplint.py and passed.

**********************************************************************

to run:
./TFractal (length of initial triangle) (number of triangles)
example:
./TFractal 200 5
