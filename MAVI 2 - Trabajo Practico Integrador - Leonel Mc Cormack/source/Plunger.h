#pragma once
#include <box2d.h>
#include "raylib.h"

class Plunger
{
private:

	b2Body* pistonBody;
	b2Body* stationaryTop;

	b2PrismaticJoint* railJoint;

public:
	Plunger(b2World& _wordl);

	void Update();
	void Draw();

	b2Body* GetBody() const;



	
};

