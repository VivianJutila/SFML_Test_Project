#include "Particle.h"

void Particle::update(float deltaTime)
{
	// WHAT ABOUT ACCELERATION?????

	// From physics: s = s0 + v*delta_t (+ 0.5*a*delta_t)
	position = position + deltaTime * velocity;
}

Particle::Particle() {
	position.x = 0.0f;
	position.y = 0.0f;

	velocity.x = 0.0f;
	velocity.y = 0.0f;

	acceleration.x = 0.0f;
	acceleration.y = 0.0f;
}
