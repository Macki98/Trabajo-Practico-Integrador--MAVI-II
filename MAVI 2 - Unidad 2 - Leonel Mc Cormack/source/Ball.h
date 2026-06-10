#pragma once
#include "raylib.h"
#include <box2d.h>
#include <vector>

class Ball
{
private:

	// Definimos las propiedades iniciales del cuerpo
	b2Body* ballBody;
	float radius;
	Color color;

public:

	Ball(b2World& _world, float _x, float _y, float _r, Color _c);


	void Draw();

	b2Body* GetBody() const;

	
};

