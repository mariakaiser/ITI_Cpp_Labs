#include "../include/shape.h"
int main()
{
    shape* c = new circle();
    shape* r = new rectangle();
    shape* s = new square();
    shape* t = new triangle();

    shape* shapes[4]; 

    shapes[0] = c;
    shapes[1] = r;
    shapes[2] = s;
    shapes[3] = t;
    sf::RenderWindow window(sf::VideoMode(1200, 800), "Shapes");

    while (window.isOpen()) 
    {
        sf::Event e;
        while (window.pollEvent(e))
            if (e.type == sf::Event::Closed) window.close();

        window.clear(sf::Color::White);

        for(int i =0;i<4;i++)
        {
            shapes[i]->draw(window);
        }
    
        window.display();
    }

    return 0;
}