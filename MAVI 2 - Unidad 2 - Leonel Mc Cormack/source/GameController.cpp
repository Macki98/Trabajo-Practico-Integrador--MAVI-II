#include "GameController.h"

GameController::GameController()
{
	// Creamos la pantalla y establemecemos el FrameRate
	const int screenWidth = 1000;
	const int screenHeight = 600;

	InitWindow(screenWidth, screenHeight, "MAVI II - Trabajo Practico Integrador - Leonel Mc Cormack");
	SetTargetFPS(60);


	plunger = new Plunger(*physicsWorld.GetB2World());

	windmills.push_back(new Windmill(*physicsWorld.GetB2World(), 250.0f, 200.0f));
	windmills.push_back(new Windmill(*physicsWorld.GetB2World(), 425.0f, 100.0f));
	windmills.push_back(new Windmill(*physicsWorld.GetB2World(), 600.0f, 200.0f));

	track = new Track(*physicsWorld.GetB2World());

	bumpers.push_back(new Bumper(*physicsWorld.GetB2World(), 230.0f, 300.0f, 15.0f));
	bumpers.push_back(new Bumper(*physicsWorld.GetB2World(), 330.0f, 350.0f, 15.0f));
	bumpers.push_back(new Bumper(*physicsWorld.GetB2World(), 430.0f, 400.0f, 15.0f));
	bumpers.push_back(new Bumper(*physicsWorld.GetB2World(), 530.0f, 350.0f, 15.0f));
	bumpers.push_back(new Bumper(*physicsWorld.GetB2World(), 630.0f, 300.0f, 15.0f));

	flippers = new Flipper(*physicsWorld.GetB2World());

}

GameController::~GameController() 
{

	for (Ball* b : balls)
	{
		delete b;
	}
	balls.clear();

	for (Bumper* b : bumpers)
	{
		delete b;
	}
	bumpers.clear();

	for (Windmill* w : windmills)
	{
		delete w;
	}
	windmills.clear();

	delete plunger;
	delete track;
	delete flippers;
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
	flippers->Update();
	physicsWorld.Update();
}

void GameController::DrawGame()
{

	BeginDrawing();
	ClearBackground(background);

	track->Draw();

	for (Bumper* b : bumpers)
	{
		b->Draw();
	}
	plunger->Draw();

	for (Windmill* w : windmills)
	{
		w->Draw();
	}

	flippers->Draw();

	for (Ball* b : balls)
	{
		b->Draw();
	}

	DrawUI();

	EndDrawing();
}

void GameController::DrawUI()
{
	
	DrawText("CONTROLES", 730.0f, 20.0f, 20, BLACK);

	DrawText("Tecla A : Flipper Izquierdo", 730.0f, 50.0f, 18, LIGHTGRAY);
	DrawText("Tecla D : Flipper Derecho", 730.0f, 75.0f, 18, LIGHTGRAY);
	DrawText("Tecla S : Cargar lanzador", 730.0f, 100.0f, 18, LIGHTGRAY);
	DrawText("Tecla B : Crear bola", 730.0f, 125.0f, 18, LIGHTGRAY);
}

void GameController::CreateBall()
{
	balls.push_back(new Ball(*physicsWorld.GetB2World(), 150.0f, plunger->GetBody()->GetPosition().y - 15.0f, 10.0f, RED));

}


