#include <SFML/System/Vector2.hpp>
#pragma once
class Particle
{
	// Required Variables:
public:
	Particle();

	void update(float deltaTime);

	// (starting)Position // vector2, X,Y components
	sf::Vector2f position;
	// Velocity // vector2, V.x, V.y components
	sf::Vector2f velocity;
	// Acceleration // vector2, A.x, A.y components
	sf::Vector2f acceleration;
	// Mass // int || float || double
	float mass;
};

