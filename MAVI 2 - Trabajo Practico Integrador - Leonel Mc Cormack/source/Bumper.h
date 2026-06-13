#pragma once
#include <box2d.h>
#include "raylib.h"

class Bumper
{
private:
	b2Body* bumperBody;

	float radius;
	Color color;

public:
	Bumper(b2World& _world, float _x, float _y, float _r);
	
	void Draw();

};


