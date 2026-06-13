#pragma once
#include <box2d.h>
#include "raylib.h"

class Track
{
private: 

	b2Body* wallR;
	b2Body* wallL;
	b2Body* top;
	b2Body* edge;
	b2Body* externWallL;
	b2Body* exit1;
	b2Body* exit2;

	Vector2 sizeWallR;
	Vector2 sizeWallL;
	Vector2 sizeEdge;
	Vector2 sizeTop;
	Vector2 sizeExit;

public:

	Track(b2World& _world);

	void Draw();

};

