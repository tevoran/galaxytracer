#include <SFML/Graphics.hpp>
#include <iostream>

int main()
{
    //starting GUI
        std::cout << "creating window\n"; //debug msg
    sf::RenderWindow window(sf::VideoMode(800,800), "galaxytracer");

    while (window.isOpen())
    {
        sf::Event event;
        while(window.pollEvent(event))
        {
            if(event.type==sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.display();
    }
    return 0;
}
