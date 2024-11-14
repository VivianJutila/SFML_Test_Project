#include <SFML/System/Vector2.hpp>
#include <SFML/Graphics.hpp>
#pragma once
class Particle
{
public:
	// Required public functions:

	// Constructor
	Particle();

	void addForce(sf::Vector2f forceVector);

	sf::Vector2f getForce() {
		return resultantForce;
	}

	inline float getMass() { return mass;  }

	inline float getInvMass() { return inverse_mass; }

	void setMass(float mass);

	void update(float deltaTime);

	// Required variables:

	// (starting)Position // vector2, X,Y components
	sf::Vector2f position;
	// Velocity // vector2, V.x, V.y components
	sf::Vector2f velocity;
	// Acceleration // vector2, A.x, A.y components
	sf::Vector2f acceleration;
	// This particles specific CircleShape
	sf::CircleShape shape;

private:
	// Force // vector2, F.x && F.y components
	sf::Vector2f resultantForce;

	// Mass // int || float || double
	float mass;
	// Inverse Mass // int || float || double
	float inverse_mass;
};

