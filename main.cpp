#include <SFML/Graphics.hpp>
#include <SFML/System/Vector2.hpp>
#include "Particle.h"
#include "GravityForce.h"
#include "AirBlowerForce.h"
#include <list>
#include <vector>
#include <iostream>
#include <cmath>

#define SCREEN_WIDTH 1600
#define SCREEN_HEIGHT 1200
#define RADIUS 5.0f
#define DELTATIME 0.016666666f
#define MAXPARTICLEAMOUNT 250

float randomFloat()
{
    return (float)(rand()) / (float)(RAND_MAX);
}

int randomInt(int a, int b)
{
    if (a > b)
        return randomInt(b, a);
    if (a == b)
        return a;
    return a + (rand() % (b - a));
}

float randomFloat(int a, int b)
{
    if (a > b)
        return randomFloat(b, a);
    if (a == b)
        return a;

    return (float)randomInt(a, b) + randomFloat();
}

int main()
{
    srand(time(0));

    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH,
        SCREEN_HEIGHT),
        "HUFFIN AND PUFFIN COPIUM TO SURVIVE!");

    // Limiting the frame rate
    window.setFramerateLimit(60);

    // LOTS OF PARTICLES
    // Container for particlesS
    // Dynamic container vector<Particle>
    std::vector<Particle> particles;

    for (int i = 0; i < MAXPARTICLEAMOUNT; i++) {
        Particle particle;
        particle.velocity = sf::Vector2f(randomFloat(0, 200.0f), randomFloat(-1, 1));
        particle.acceleration = sf::Vector2f(randomFloat(0, 20.0f), randomFloat(-.4f, .4f));
        particle.position = sf::Vector2f(randomFloat(.01, 10), randomFloat(0.01f, 1.0f));
        particle.setMass(randomFloat(2.5f, 15.0f));

        sf::CircleShape parshap(RADIUS);
        parshap.setOutlineThickness(2.5f);

        particle.shape = parshap;

        particles.push_back(particle);
    }
    
    // Gravity force object
    GravityForce gf;

    // AirBlower force object 1
    AirBlowerForce abf1;
    abf1.pos = sf::Vector2f(SCREEN_WIDTH - abf1.size.x, abf1.pos.y);
    sf::RectangleShape rect1(abf1.size);
    rect1.setFillColor(sf::Color(100, 100, 255, 100));
    rect1.setPosition(abf1.pos);
    std::cout << abf1.pos.x << "\n";

    // AirBlower force object 2
    AirBlowerForce abf2;
    abf2.pos = sf::Vector2f(0, abf2.pos.y);
    sf::RectangleShape rect2(abf2.size);
    rect2.setPosition(abf2.pos);
    rect2.setFillColor(sf::Color(100, 100, 255, 100));
    std::cout << abf2.pos.x << "\n";

    abf2.pos = sf::Vector2f(0, 500.0f);

    // shape :c

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


        // "GAME" UPDATE
        // - physics simulation update
        // Particle-class update()???
        for (int i = 0; i < MAXPARTICLEAMOUNT; i++) {
            if (particles[i].position.x <= 0 || particles[i].position.x >= SCREEN_WIDTH) {
                particles[i].acceleration.x *= -1;
                particles[i].velocity.x *= -1;
            }
            if (particles[i].position.y <= 0 || particles[i].position.y >= SCREEN_HEIGHT) {
                particles[i].acceleration.y *= -1;
                particles[i].velocity.y *= -1;
            }
            particles[i].shape.setFillColor(sf::Color(0, 255, 120, 255));
            particles[i].shape.setOutlineColor(sf::Color(0, 255, 120, 255));
            //std::cout << particles[i].getForce().x << ".x : " << particles[i].getForce().y << ".y\n";
            particles[i].update(DELTATIME); // delta time?
            gf.updateForce(particles[i]);
            abf1.updateForce(particles[i]);
            abf2.updateForce(particles[i]);
        }


        //RENDER
        window.clear();
        // Render ALL particles
        // - move shape to correct position
        // - draw shape into window
        for (Particle particle : particles) {
            particle.shape.setPosition(sf::Vector2f(particle.position.x, SCREEN_HEIGHT - particle.position.y - RADIUS * 2));
            window.draw(particle.shape);
        }
        window.draw(rect1);
        window.draw(rect2);
        window.display();
        frame++;
    }

    return 0;
}