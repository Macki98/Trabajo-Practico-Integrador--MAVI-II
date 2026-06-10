#include "GameController.h"

GameController::GameController()
{
	// Creamos la pantalla y establemecemos el FrameRate
	const int screenWidth = 1000;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "MAVI II - Unidad 1 - Leonel Mc Cormack");
	SetTargetFPS(60);

	// A su vez, establecemos el piso de nuestro muendo
	physicsWorld.AddFloor();

	plunger = new Plunger(*physicsWorld.GetB2World());

	windmill = new Windmill(*physicsWorld.GetB2World(),400.0f,300.0f);

	track = new Track(*physicsWorld.GetB2World());
}

GameController::~GameController() 
{
	
}

// Loop principal que se ejecutara hasta cerrar la ventana
void GameController::RunMainLoop()
{
	
	while (!WindowShouldClose())
	{
		Events();
		UpdateGame();
		DrawGame();
	}

	CloseWindow();
}

void GameController::Events()
{
	plunger->Update();
}

void GameController::UpdateGame()
{
	if (IsKeyPressed(KEY_B))
	{
		CreateBall();
	}
	plunger->Update();
	physicsWorld.Update();
}

void GameController::DrawGame()
{

	BeginDrawing();
	ClearBackground(background);

	physicsWorld.Draw();

	track->Draw();

	plunger->Draw();
	windmill->Draw();

	for (Ball& b : balls)
	{
		b.Draw();
	}

	EndDrawing();
}

void GameController::CreateBall()
{
	balls.push_back(Ball(*physicsWorld.GetB2World(), 150.0f, plunger->GetBody()->GetPosition().y - 15.0f, 10.0f, RED));
	//balls.push_back(Ball(*physicsWorld.GetB2World(), 410.0f, 150.0f, 15.0f, RED));
}


