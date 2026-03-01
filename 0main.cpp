#include "all-cells.hpp"
#include "POI.hpp"

// #include <SFML/Graphics.hpp>
#include <iostream>
// #include <vector>
#include <string>

int main() {
    std::cout << "test" << std::endl;
    return 0;
}

/*
void drawGrid(sf::RenderWindow* window, float scale) {

    sf::VertexArray grid(sf::Lines);
    sf::Color gridColor(100, 100, 100);
    sf::Color gridCenterColor(200, 200, 200);
    unsigned int sizeX = window->getSize().x;
    unsigned int sizeY = window->getSize().y;

    while ( window->getSize().x > 20*scale
        || window->getSize().y > 20*scale )
        scale *= 2;
     
    // grid

    for (int i = 1; i <= window->getSize().x / 2; i++) 
    {
        grid.append(sf::Vertex(sf::Vector2f(sizeX/2 + i*scale, 0.f), gridColor));
        grid.append(sf::Vertex(sf::Vector2f(sizeX/2 + i*scale, sizeY), gridColor));
        grid.append(sf::Vertex(sf::Vector2f(sizeX/2 + -i*scale, 0.f), gridColor));
        grid.append(sf::Vertex(sf::Vector2f(sizeX/2 + -i*scale, sizeY), gridColor));
    }
    for (int i = 1; i <= window->getSize().y / 2; i++)
    {
        grid.append(sf::Vertex(sf::Vector2f(0.f, sizeY/2 + i*scale), gridColor));
        grid.append(sf::Vertex(sf::Vector2f(sizeX, sizeY/2 + i*scale), gridColor));
        grid.append(sf::Vertex(sf::Vector2f(0.f, sizeY/2 - i*scale), gridColor));
        grid.append(sf::Vertex(sf::Vector2f(sizeX, sizeY/2 - i*scale), gridColor));
    }

    // white 0, 0 cross

    grid.append(sf::Vertex(sf::Vector2f(sizeX/2, 0.f), gridCenterColor));
    grid.append(sf::Vertex(sf::Vector2f(sizeX/2, sizeY), gridCenterColor));
    
    grid.append(sf::Vertex(sf::Vector2f(0.f, sizeY/2), gridCenterColor));
    grid.append(sf::Vertex(sf::Vector2f(sizeX, sizeY/2), gridCenterColor));

    window->draw(grid);
}

int main()
{
    std::cout << "Running main" << std::endl;

    // window setup

    sf::RenderWindow window(sf::VideoMode(1000, 1000), "Cells & trees");
    const unsigned int FPS = 120;
    window.setFramerateLimit(FPS);

    sf::Image icon;
    if (!icon.loadFromFile("icon.png"))
        return EXIT_FAILURE;
    window.setIcon(icon.getSize().x, icon.getSize().y, icon.getPixelsPtr());

    sf::Clock clock;
    sf::Time timeSinceLastUpdate = sf::Time::Zero;
    const sf::Time TimePerTick = sf::seconds(1.f / 20.f); // 1 second / X ticks

    sf::Font font;
    if (!font.loadFromFile("arialmt.ttf"))
        return EXIT_FAILURE;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(50);
    text.setFillColor(sf::Color::White);
    text.setPosition(100.f, 100.f);

    float scale = 120; // pixels per length unit

    // 2D game "scene" setup

    democell* zero = new democell(0, 0);
    zero->IsStem = true;

    std::vector<lightspot> lights;
    lights.push_back(lightspot(10, 10));

    std::vector<mineralspot> minerals;
    minerals.push_back(mineralspot(10, -10));

    // game cycle

    while (window.isOpen())
    {
        sf::Time elapsed = clock.restart();
        timeSinceLastUpdate += elapsed;

        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            if (event.type == sf::Event::Resized)
            {
                sf::FloatRect visibleArea(0, 0, event.size.width, event.size.height);
                window.setView(sf::View(visibleArea));
            }
        }

        // tick actions

        while (timeSinceLastUpdate > TimePerTick) {
            timeSinceLastUpdate -= TimePerTick;
            //process_tree(zero);
            
            scale *= 0.995;
            
            zero->x += 0.001 * TimePerTick.asMilliseconds();
            
            if ( zero->x * scale >= window.getSize().x/2 )
                zero->x = 0;
        }

        // display

        window.clear(sf::Color(3, 16, 25));
        drawGrid(&window, scale);
        
        for (unsigned int i=0; i<minerals.size(); i++) {
            minerals[i].display(&window);
        }

        display_tree(&window, zero, scale);

        for (unsigned int i=0; i<lights.size(); i++) {
            lights[i].display(&window);
        }

        window.display();
    }
    
    std::cout << "Exit (success)" << std::endl;
    return 0;
}
*/