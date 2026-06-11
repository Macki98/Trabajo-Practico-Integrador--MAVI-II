#include "Plunger.h"

Plunger::Plunger(b2World& _world)
{
	// Tope Fijo Inferior
	b2BodyDef stationaryDef;
	stationaryDef.type = b2_staticBody;
	stationaryDef.position.Set(150.0f, (float)GetScreenHeight() - 80.0f);
	stationaryTop = _world.CreateBody(&stationaryDef);

	b2PolygonShape stationaryShape;
	stationaryShape.SetAsBox(15.0f, 5.0f);

	b2FixtureDef fixtureSDef;
	fixtureSDef.shape = &stationaryShape;
	stationaryTop->CreateFixture(&fixtureSDef);

	// Piston movil
	b2BodyDef pistonDef;
	pistonDef.type = b2_dynamicBody;
	pistonDef.position.Set(150.0f, 400.0f);
	pistonBody = _world.CreateBody(&pistonDef);

	b2PolygonShape boxShape;
	boxShape.SetAsBox(10.0f, 5.0f);

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &boxShape;
	fixtureDef.density = 0.01f;
	pistonBody->CreateFixture(&fixtureDef);
	
	// Regla 2: Riel (prismatic joint)
	b2PrismaticJointDef prismaticDef;
	b2Vec2 axisY(0.0f, 1.0f);

	prismaticDef.Initialize(stationaryTop, pistonBody, pistonBody->GetPosition(), axisY);

	prismaticDef.collideConnected = false;
	prismaticDef.enableLimit = true;
	prismaticDef.lowerTranslation = 0.0f;
	prismaticDef.upperTranslation = 0.0f;

	railJoint = (b2PrismaticJoint*)_world.CreateJoint(&prismaticDef);
}


void Plunger::Update()
{
	if (IsKeyDown(KEY_S))
	{
		pistonBody->SetAwake(true);

		railJoint->SetLimits(0.0f, 80.0f);


		pistonBody->SetLinearVelocity(b2Vec2(0.0f, 10.0f));
	}

	if (IsKeyReleased(KEY_S))
	{
		pistonBody->SetAwake(true);
		
		railJoint->SetLimits(0.0f, 0.0f);

		pistonBody->SetLinearVelocity(b2Vec2(0.0f, -500.0f));
	}
}

void Plunger::Draw()
{

	b2Vec2 pos = pistonBody->GetPosition();
	float angle = pistonBody->GetAngle() * RAD2DEG;
	
	Rectangle rect = { pos.x,pos.y, 30.0f,10.0f };
	Vector2 origin = { 30.0f / 2.0f, 10.0f / 2.0f };

	DrawRectanglePro(rect, origin, angle, YELLOW);

}

b2Body* Plunger::GetBody() const
{
	return pistonBody;
}


