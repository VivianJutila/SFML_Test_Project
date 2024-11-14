#include "Particle.h"
#include <iostream>

void Particle::update(float deltaTime)
{
	// WHAT ABOUT ACCELERATION?????
	acceleration = inverse_mass * resultantForce;

	velocity = acceleration * deltaTime + velocity;

	// From physics: s = s0 + v*delta_t + (0.5*a*delta_t)
	position = position + velocity * deltaTime; //+ (0.5f * acceleration * deltaTime);

	resultantForce = sf::Vector2f(0.0f, 0.0f);
}

Particle::Particle() {
	position.x = 0.0f;
	position.y = 0.0f;

	velocity.x = 0.0f;
	velocity.y = 0.0f;

	acceleration.x = 0.0f;
	acceleration.y = 0.0f;

	mass = 1.0f;
	inverse_mass = 1.0f;
}

void Particle::addForce(sf::Vector2f forceVector) {
	resultantForce += forceVector;
}

void Particle::setMass(float m) {
	if (m > 0.0001f) {
		mass = m;
		inverse_mass = 1.0f / m;
	}
}