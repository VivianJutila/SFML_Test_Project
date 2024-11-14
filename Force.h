#pragma once
#include "Particle.h"
class Force
{
public:
	virtual void updateForce(Particle&p) = 0;
};

