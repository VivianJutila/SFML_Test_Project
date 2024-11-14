#pragma once
#include "Force.h"
class GravityForce : Force
{
public:
	float gravity = -9.81f;

	void updateForce(Particle&p);
};

