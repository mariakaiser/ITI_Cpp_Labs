#include <SFML/Graphics.hpp>
#include <string>

class shape{
    public:
    virtual void draw(sf::RenderWindow& window) = 0;
};

class circle: public shape
{
    sf::CircleShape c;

    int radius;
    // the origin is the top-left corner of the circle's bounding square, not its center.
    int row;
    int col;

    public:
    circle();
    circle(int radius, int row, int col);
    void draw(sf::RenderWindow& window) override;
};

class rectangle: public shape
{
    sf::RectangleShape r;
    int width;
    int height;
    // the origin is the top-left corner of the rectangle
    int row;
    int col;

    public:
    rectangle();
    rectangle(int width, int height , int row , int col);

    void draw(sf::RenderWindow& window) override;
};

class square: public shape
{
    sf::RectangleShape s;
    int width;
    int height;
    // the origin is the top-left corner of the rectangle
    int row;
    int col;

    public:
    square();
    square(int width, int height , int row , int col);

    void draw(sf::RenderWindow& window) override;
};

class triangle: public shape
{
    /* A CircleShape is really a regular polygon whose second argument is the number of sides. 
    With 3, you get an equilateral triangle */
    sf::CircleShape t; 

    int radius;
    // the origin is the top-left corner of the circle's bounding square, not its center.
    int row;
    int col;

    public:
    triangle();
    triangle(int radius, int row, int col);

    void draw(sf::RenderWindow& window) override;
};