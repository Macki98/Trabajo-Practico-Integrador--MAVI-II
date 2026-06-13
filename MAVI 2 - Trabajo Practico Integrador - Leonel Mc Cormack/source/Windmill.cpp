#include "Windmill.h"

Windmill::Windmill(b2World& _world, float _x, float _y)
{
	// Eje estatico que permite rotacion
	b2BodyDef axisDef;
	axisDef.type = b2_staticBody;
	axisDef.position.Set(_x,_y);
	staticAxis = _world.CreateBody(&axisDef);

	b2PolygonShape axisShape;
	axisShape.SetAsBox(2.5f, 2.5f);
	staticAxis->CreateFixture(&axisShape,0.0f);

	// Creamos la Definicion que tendran las aspas del molino
	b2BodyDef poleADef;
	poleADef.type = b2_dynamicBody;
	poleADef.position.Set(_x, _y);
	pole = _world.CreateBody(&poleADef);

	// Asignamos una forma a cada aspa
	b2PolygonShape shapeA;
	shapeA.SetAsBox(40.0f, 5.0f);
	pole->CreateFixture(&shapeA, 0.1f);

	b2PolygonShape shapeB;
	shapeB.SetAsBox(5.0f, 40.0f);
	pole->CreateFixture(&shapeB, 0.1f);

	// Joint que permite la rotacion
	b2RevoluteJointDef revoluteDef;
	revoluteDef.Initialize(staticAxis, pole, b2Vec2(_x, _y));

	revoluteDef.enableMotor = true;
	revoluteDef.motorSpeed = 4.0f;
	revoluteDef.maxMotorTorque = 50000.0f;

	revoluteJoint = (b2RevoluteJoint*)_world.CreateJoint(&revoluteDef);
}

void Windmill::Draw()
{
	// Aspa A
	b2Vec2 posA = pole->GetPosition();
	float angleA = pole->GetAngle() * RAD2DEG;

	Rectangle rectA = { posA.x,posA.y,80.0f,10.0f };
	Vector2 centerA = { 80.0f / 2, 10.0f / 2 };

	DrawRectanglePro(rectA, centerA, angleA, MAROON);

	// Aspa B
	Rectangle rectB = { posA.x,posA.y,10.f,80.f };
	Vector2 centerB = { 10.0f / 2, 80.0f / 2 };

	DrawRectanglePro(rectB, centerB, angleA, GREEN);

	// Punto de Anclaje
	DrawCircle(posA.x, posA.y, 2.5f, BLACK);
}
