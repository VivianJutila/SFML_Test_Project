#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Particle.h"

#define SCREEN_WIDTH 900
#define SCREEN_HEIGHT 600
#define RADIUS 50.0f
#define DELTATIME = 0.016666666f
#define SCALE 40.0f

int main()
{
    sf::Vector2f v1(0.99f, 0.99f);

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,
                                          SCREEN_HEIGHT),
                                          "HUFFIN AND PUFFIN COPIUM TO SURVIVE!");

    // Limiting the frame rate
    window.setFramerateLimit(60);

    // PARTICLE
    Particle p; // Calling default constructor
    p.velocity.x = 200.0f;
    p.acceleration.x = 200.0f;
    p.velocity.y = 20.0f;
    p.acceleration.y = 20.0f;

    // LOTS OF PARTICLES
    // Container for particles
    // Dynamic container vector<Particle>

    //shape
    sf::CircleShape shape(RADIUS);
    shape.setFillColor(sf::Color(0,0,0,0));
    shape.setOutlineColor(sf::Color(255, 194, 38, 255));
    shape.setOutlineThickness(5.0f);

    //parshap
    sf::CircleShape parshap(RADIUS);
    parshap.setFillColor(sf::Color(0, 0, 0, 0));
    parshap.setOutlineColor(sf::Color(255, 194, 38, 255));
    parshap.setOutlineThickness(5.0f);

    sf::Vector2f v2 = shape.getScale();

    bool expand = false;
    float frame = 0.0f;
    while (window.isOpen())
    {
        // INPUT SYSTEM
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        shape.setPosition((int)(frame/shape.getScale().x) % SCREEN_WIDTH, SCREEN_HEIGHT / 2 - (RADIUS * shape.getScale().x));

        // "GAME" UPDATE
        // - physics simulation update
        // Particle-class update()???
        p.update(0.01666666666666f); // delta time?

        parshap.setPosition(p.position.x,
                            (SCREEN_HEIGHT - RADIUS*2) - p.position.y);

        if (shape.getScale().x < 0.01f) {
            shape.setScale(v2);
        }
        else {
            shape.scale(v1);
        }

        //RENDER
        window.clear();
        // Render ALL particles
        // - move shape to correct position
        // - draw shape into window
        window.draw(shape);
        window.draw(parshap);
        window.display();
        frame++;
    }

    return 0;
}