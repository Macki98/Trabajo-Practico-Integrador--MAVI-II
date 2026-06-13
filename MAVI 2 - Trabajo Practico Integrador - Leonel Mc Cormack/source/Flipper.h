#pragma once
#include <box2d.h>
#include "raylib.h"

class Flipper
{
private:

	b2Body* flipper1Body;
	b2Body* flipper2Body;

	b2RevoluteJoint* revolute1Joint;
	b2RevoluteJoint* revolute2Joint;

	Vector2 flipperSize;

public:

	Flipper(b2World& _wordl);

	void Update();
	void Draw();

};

