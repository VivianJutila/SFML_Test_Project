#include "GravityForce.h"

void GravityForce::updateForce(Particle&p) {
	
	sf::Vector2f force = sf::Vector2f(0, this->gravity);
	force *= p.getMass();

	p.addForce(force);
}