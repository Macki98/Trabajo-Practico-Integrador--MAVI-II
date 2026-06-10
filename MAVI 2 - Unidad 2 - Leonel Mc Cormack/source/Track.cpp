#include "Track.h"

Track::Track(b2World& _world)
{
	sizeWallR = { 10.0f, 600.0f }; 
	sizeWallL = { 10.0f, 500.0f };
	sizeEdge = { 80.0f, 10.0f };
	sizeTop = { 600.0f, 10.0f };
	sizeExit = { 300.0f, 10.0f };


	// 1. Techo
	b2BodyDef topDef;
	topDef.type = b2_staticBody;
	topDef.position.Set(420.0f, 5.0f);
	
	top = _world.CreateBody(&topDef);

	b2PolygonShape topShape;
	topShape.SetAsBox(sizeTop.x / 2.0f, sizeTop.y / 2.0f);
	
	top->CreateFixture(&topShape, 0.0f);

	// 2. Pared externa Izq
	b2BodyDef wallRDef;
	wallRDef.type = b2_staticBody;
	wallRDef.position.Set(125.0f, 300.0f);
	
	wallR = _world.CreateBody(&wallRDef);

	b2PolygonShape wallRShape;
	wallRShape.SetAsBox(sizeWallR.x / 2.0f, sizeWallR.y / 2.0f);
	
	wallR->CreateFixture(&wallRShape, 0.0f);

	// 3. Pared interna Der
	b2BodyDef wallLDef;
	wallLDef.type = b2_staticBody;
	wallLDef.position.Set(175.0f, 350.0f);
	
	wallL = _world.CreateBody(&wallLDef);

	b2PolygonShape wallLShape;
	wallLShape.SetAsBox(sizeWallL.x /2.0f, sizeWallL.y/2.0f);

	wallL->CreateFixture(&wallLShape,0.0f);

	// 4. Corner
	b2BodyDef edgeDef;
	edgeDef.type = b2_staticBody;
	edgeDef.position.Set(155.0f, 30.f);
	float angleRad = -45.0f * DEG2RAD;
	edgeDef.angle = angleRad;

	edge = _world.CreateBody(&edgeDef);
	
	b2PolygonShape edgeShape;
	edgeShape.SetAsBox(sizeEdge.x /2.0f, sizeEdge.y/2.0f);
	
	edge->CreateFixture(&edgeShape, 0.0f);

	// 5. Pared externa Der
	b2BodyDef externDef;
	externDef.type = b2_staticBody;
	externDef.position.Set(715.0f, 300.0f);
	externWallL = _world.CreateBody(&externDef);

	b2PolygonShape externShape;
	externShape.SetAsBox(sizeWallR.x / 2.0f, sizeWallR.y / 2.0f);

	externWallL->CreateFixture(&externShape, 0.0f);

	// 6. Salidas
	// salida 1
	b2BodyDef exit1Def;
	exit1Def.type = b2_staticBody;
	exit1Def.position.Set(280.0f, 490.0f);
	float angleExit1 = 45.0f * DEG2RAD;
	exit1Def.angle = angleExit1;

	exit1 = _world.CreateBody(&exit1Def);

	b2PolygonShape exit1Shape;
	exit1Shape.SetAsBox(sizeExit.x / 2.0f, sizeExit.y / 2.0f);

	exit1->CreateFixture(&exit1Shape, 0.0f);

	// salida 2
	b2BodyDef exit2Def;
	exit2Def.type = b2_staticBody;
	exit2Def.position.Set(610.0f, 490.0f);
	float angleExit2 = -45.0f * DEG2RAD;
	exit2Def.angle = angleExit2;

	exit2 = _world.CreateBody(&exit2Def);

	b2PolygonShape exit2Shape;
	exit2Shape.SetAsBox(sizeExit.x / 2.0f, sizeExit.y / 2.0f);

	exit2->CreateFixture(&exit2Shape, 0.0f);
}

void Track::Draw()
{

	// Techo
	b2Vec2 posTop = top->GetPosition();
	Rectangle rectTop = { posTop.x,posTop.y,sizeTop.x,sizeTop.y };
	Vector2 centerTop = { sizeTop.x / 2.0f,sizeTop.y / 2.0f };
	DrawRectanglePro(rectTop, centerTop, 0.0f, LIGHTGRAY);

	// Pared Externa Derecha
	b2Vec2 posExtern = externWallL->GetPosition();
	Rectangle rectExtern = { posExtern.x, posExtern.y, sizeWallR.x, sizeWallR.y };
	Vector2 centerExtern = { sizeWallR.x / 2.0f, sizeWallR.y / 2.0f };
	DrawRectanglePro(rectExtern, centerExtern, 0.0f, LIGHTGRAY);

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

	// Salida 1
	b2Vec2 posExit1 = exit1->GetPosition();
	float angleExit1 = exit1->GetAngle() * RAD2DEG;
	Rectangle rectExit1 = { posExit1.x, posExit1.y, sizeExit.x, sizeExit.y };
	Vector2 centerExit1 = { sizeExit.x / 2.0f, sizeExit.y / 2.0f };
	DrawRectanglePro(rectExit1, centerExit1, angleExit1, LIGHTGRAY);

	// Salida 2
	b2Vec2 posExit2 = exit2->GetPosition();
	float angleExit2 = exit2->GetAngle() * RAD2DEG;
	Rectangle rectExit2 = { posExit2.x, posExit2.y, sizeExit.x, sizeExit.y };
	Vector2 centerExit2 = { sizeExit.x / 2.0f, sizeExit.y / 2.0f };
	DrawRectanglePro(rectExit2, centerExit2, angleExit2, LIGHTGRAY);

}
