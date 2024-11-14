#pragma once
#include "Force.h"

class AirBlowerForce : Force
{
public:
	sf::Vector2f size = sf::Vector2f(300.0f, 900.0f);

	sf::Vector2f pos = sf::Vector2f(0, 1200.0f - size.y);

	float force_amount = 150.0f;

	void updateForce(Particle& p);
};

