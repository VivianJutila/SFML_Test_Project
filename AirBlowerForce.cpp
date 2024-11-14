#include "AirBlowerForce.h"
#include <iostream>

void AirBlowerForce::updateForce(Particle& p) {
	if (p.position.x <= pos.x + size.x && p.position.x >= pos.x) {

		sf::Vector2f force = sf::Vector2f(0, this->force_amount);

		p.addForce(force);
	}
}