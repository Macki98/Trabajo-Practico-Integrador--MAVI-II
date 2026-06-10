#include "Track.h"

Track::Track(b2World& _world)
{
	sizeWallR = { 10.0f, 600.0f }; 
	sizeWallL = { 10.0f, 500.0f };
	sizeEdge = { 80.0f, 10.0f };

	// 1. Pared externa Izq
	b2BodyDef wallRDef;
	wallRDef.type = b2_staticBody;
	wallRDef.position.Set(125.0f, 300.0f);
	wallR = _world.CreateBody(&wallRDef);

	b2PolygonShape wallRShape;
	wallRShape.SetAsBox(sizeWallR.x / 2.0f, sizeWallR.y / 2.0f);
	wallR->CreateFixture(&wallRShape, 0.0f);

	// 2. Pared interna Der
	b2BodyDef wallLDef;
	wallLDef.type = b2_staticBody;
	wallLDef.position.Set(175.0f, 350.0f);
	wallL = _world.CreateBody(&wallLDef);

	b2PolygonShape wallLShape;
	wallLShape.SetAsBox(sizeWallL.x /2.0f, sizeWallL.y/2.0f);

	wallL->CreateFixture(&wallLShape,0.0f);

	// 3. Corner
	b2BodyDef edgeDef;
	edgeDef.type = b2_staticBody;
	edgeDef.position.Set(155.0f, 30.f);

	float angleRad = -45.0f * DEG2RAD;
	edgeDef.angle = angleRad;

	edge = _world.CreateBody(&edgeDef);
	
	b2PolygonShape edgeShape;

	edgeShape.SetAsBox(sizeEdge.x /2.0f, sizeEdge.y/2.0f);
	edge->CreateFixture(&edgeShape, 0.0f);

}

void Track::Draw()
{
	// ---- 1. DIBUJAR PARED IZQ ----
	b2Vec2 posR = wallR->GetPosition();
	Rectangle rectR = { posR.x, posR.y, sizeWallR.x, sizeWallR.y };
	Vector2 centerR = { sizeWallR.x / 2.0f, sizeWallR.y / 2.0f };
	DrawRectanglePro(rectR, centerR, 0.0f, LIGHTGRAY);

	// ---- 2. DIBUJAR PARED DER ----
	b2Vec2 posL = wallL->GetPosition();
	Rectangle rectL = { posL.x, posL.y, sizeWallL.x, sizeWallL.y };
	Vector2 centerL = { sizeWallL.x / 2.0f, sizeWallL.y / 2.0f };
	DrawRectanglePro(rectL, centerL, 0.0f, LIGHTGRAY);

	// ---- 3. DIBUJAR CORNER ----
	b2Vec2 posEdge = edge->GetPosition();
	float angleEdge = edge->GetAngle() * RAD2DEG;

	Rectangle rectEdge = { posEdge.x, posEdge.y, sizeEdge.x, sizeEdge.y };
	Vector2 centerEdge = { sizeEdge.x / 2.0f, sizeEdge.y / 2.0f };
	DrawRectanglePro(rectEdge, centerEdge, angleEdge, LIGHTGRAY);

}
