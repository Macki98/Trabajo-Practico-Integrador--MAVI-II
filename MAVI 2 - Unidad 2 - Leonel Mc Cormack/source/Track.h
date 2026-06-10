#pragma once
#include <box2d.h>
#include "raylib.h"

class Track
{
private: 

	b2Body* wallR;
	b2Body* wallL;
	b2Body* edge;

	Vector2 sizeWallR;
	Vector2 sizeWallL;
	Vector2 sizeEdge;

public:

	Track(b2World& _world);

	void Draw();

};

