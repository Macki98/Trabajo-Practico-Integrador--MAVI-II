#pragma once
#include <box2d.h>
#include "raylib.h"

class Windmill
{
private:

	b2Body* pole;

	b2Body* staticAxis;

	b2RevoluteJoint* revoluteJoint;

public:

	Windmill(b2World& _world, float _x, float _y);

	void Update();
	void Draw();
};

