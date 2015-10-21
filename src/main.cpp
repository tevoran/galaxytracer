#include <SFML/Graphics.hpp>
#include <iostream>
#include "header/gt.hpp"

int main()
{
    //reading configfile
        std::cout << "reading data/config\n";
    gt::config config_gt; //this reads data/config


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
