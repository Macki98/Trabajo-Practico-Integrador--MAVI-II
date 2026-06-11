#pragma once
#include "raylib.h"
#include <box2d.h>
#include <vector>
#include "World.h"
#include "Plunger.h"
#include "Ball.h"
#include "Windmill.h"
#include "Track.h"
#include "Bumper.h"
#include "Flipper.h"

class GameController
{
private:
	
	/*
		Le damos un atributo World para crear ese mundo fisico
	*/
	World physicsWorld;

	Color background = { 110, 100, 215, 255 };

	Plunger* plunger;

	std::vector<Ball*> balls;
	std::vector<Windmill*> windmills;

	Track* track;

	std::vector<Bumper*> bumpers;

	Flipper* flippers;
	

public:

	GameController();
	~GameController();

	void RunMainLoop();

	void Events();
	void UpdateGame();
	void DrawGame();

	void DrawUI();
	void CreateBall();
};

