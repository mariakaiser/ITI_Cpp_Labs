#include <iostream>
#include "../include/shape.h"

// -------------- Circle -----------------
circle::circle()
{
    this->radius = 50;
    this->row = 100;
    this->col = 100;
}
circle::circle(int radius, int row, int col)
{
    this->radius = radius;
    this->row = row;
    this->col = col;
}

void circle::draw(sf::RenderWindow& window)
{
    c.setFillColor(sf::Color::Blue);
    c.setRadius(this->radius);
    c.setPosition(this->row, this->col);

    window.draw(this->c);
}

// -------------- Rectangle----------------

rectangle::rectangle()
{
    this->width = 200;
    this->height = 100;
    this->row = 300;
    this->col = 200;
}

rectangle::rectangle(int width, int height, int row, int col)
{
    this->width = width;
    this->height = height;
    this->row = row;
    this->col = col;
}

void rectangle::draw(sf::RenderWindow& window)
{
    r.setSize(sf::Vector2f(this->width, this->height));
    r.setFillColor(sf::Color::Green);
    r.setPosition(this->row, this->col);  // top-left corner

    window.draw(this->r);
}

// -------------- Square ----------------

square::square()
{
    this->width = 100;
    this->height = 100;
    this->row = 600;
    this->col = 200;
}

square::square(int width, int height, int row, int col)
{
    if (width != height)
    {
        std::cout<<"invalid dimensions for a square " << std::endl;
        return;
    }
    this->width = width;
    this->height = height;
    this->row = row;
    this->col = col;
}

void square::draw(sf::RenderWindow& window)
{
    s.setSize(sf::Vector2f(this->width, this->height));
    s.setFillColor(sf::Color::Green);
    s.setPosition(this->row, this->col);  // top-left corner

    window.draw(this->s);
}

// -------------- Triangle ----------------

triangle::triangle()
{
    this->radius = 50;
    this->row = 800;
    this->col = 100;
}
triangle::triangle(int radius, int row, int col)
{
    this->radius = radius;
    this->row = row;
    this->col = col;
}

void triangle::draw(sf::RenderWindow& window)
{
    t.setPointCount(3); // to force it being a triangle
    t.setFillColor(sf::Color::Blue);
    t.setRadius(this->radius);
    t.setPosition(this->row, this->col);

    window.draw(this->t);
}