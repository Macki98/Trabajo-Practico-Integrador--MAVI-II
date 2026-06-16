#include "Flipper.h"

Flipper::Flipper(b2World& _wordl)
{
	flipperSize = { 50.0f, 10.0f };


	// Anclaje estatico

	b2BodyDef anchorDef;
	anchorDef.type = b2_staticBody;
	anchorDef.position.Set(0.0f, 0.0f);
	b2Body* staticAnchor = _wordl.CreateBody(&anchorDef);

	// Flipper 1

	b2BodyDef flipper1Def;
	flipper1Def.type = b2_dynamicBody;
	flipper1Def.position.Set(385.0f, 570.0f);
	float angleRepose1 = 20.0f * DEG2RAD;
	flipper1Def.angle = angleRepose1;

	flipper1Body = _wordl.CreateBody(&flipper1Def);

	b2PolygonShape flipper1Shape;
	flipper1Shape.SetAsBox(flipperSize.x / 2.0f, flipperSize.y / 2.0f);

	b2FixtureDef flipper1Fixture;
	flipper1Fixture.shape = &flipper1Shape;
	flipper1Fixture.density = 2.0f;
	flipper1Fixture.friction = 0.1f;
	flipper1Fixture.restitution = 0.1f;

	flipper1Body->CreateFixture(&flipper1Fixture);

	// Flipper 2

	b2BodyDef flipper2Def;
	flipper2Def.type = b2_dynamicBody;
	flipper2Def.position.Set(510.0f, 570.0f);
	float angleRepose2 = -20.0f * DEG2RAD;
	flipper2Def.angle = angleRepose2;

	flipper2Body = _wordl.CreateBody(&flipper2Def);

	b2PolygonShape flipper2Shape;
	flipper2Shape.SetAsBox(flipperSize.x / 2.0f, flipperSize.y / 2.0f);

	b2FixtureDef flipper2Fixture;
	flipper2Fixture.shape = &flipper2Shape;
	flipper2Fixture.density = 2.0f;
	flipper2Fixture.friction = 0.1f;
	flipper2Fixture.restitution = 0.1f;

	flipper2Body->CreateFixture(&flipper2Fixture);

	// Revolute Joint 1

	b2RevoluteJointDef joint1Def;
	b2Vec2 pivot1 = b2Vec2(355.0f, 570.0f);
	joint1Def.Initialize(staticAnchor, flipper1Body, pivot1);

	joint1Def.enableLimit = true;
	joint1Def.lowerAngle = -50.0f * DEG2RAD;
	joint1Def.upperAngle = 0.0f * DEG2RAD;

	joint1Def.enableMotor = true;
	joint1Def.maxMotorTorque = 5000000.0f;
	joint1Def.motorSpeed = 0.0f;

	revolute1Joint = (b2RevoluteJoint*)_wordl.CreateJoint(&joint1Def);
	
	// Revolute Joint 2

	b2RevoluteJointDef joint2Def;
	b2Vec2 pivot2 = b2Vec2(540.0f, 570.0f);
	joint2Def.Initialize(staticAnchor, flipper2Body, pivot2);

	joint2Def.enableLimit = true;
	joint2Def.lowerAngle = 0.0f * DEG2RAD;
	joint2Def.upperAngle = 50.0f * DEG2RAD;

	joint2Def.enableMotor = true;
	joint2Def.maxMotorTorque = 5000000.0f;
	joint2Def.motorSpeed = 0.0f;

	revolute2Joint = (b2RevoluteJoint*)_wordl.CreateJoint(&joint2Def);
}

void Flipper::Update()
{
	if (IsKeyDown(KEY_A))
	{
		flipper1Body->SetAwake(true);

		revolute1Joint->SetMotorSpeed(-5000000.0f);
	}
	else 
	{ 
		revolute1Joint->SetMotorSpeed(15.0f);
	}

	if (IsKeyDown(KEY_D))
	{
		flipper2Body->SetAwake(true);

		revolute2Joint->SetMotorSpeed(5000000.0f);
	}
	else 
	{
		revolute2Joint->SetMotorSpeed(-15.0f);
	}
}

void Flipper::Draw()
{
	
	// Flipper 1
	b2Vec2 pos1 = flipper1Body->GetPosition();
	float angle1 = flipper1Body->GetAngle() * RAD2DEG;
	Rectangle rect1 = { pos1.x, pos1.y, flipperSize.x, flipperSize.y };

	Vector2 origin1 = { 0.0f, flipperSize.y / 2.0f };
	DrawRectanglePro(rect1, origin1, angle1, RED);

	// Flipper 2
	b2Vec2 pos2 = flipper2Body->GetPosition();
	float angle2 = flipper2Body->GetAngle() * RAD2DEG;
	Rectangle rect2 = { pos2.x, pos2.y, flipperSize.x, flipperSize.y };

	Vector2 origin2 = { flipperSize.x, flipperSize.y / 2.0f };
	DrawRectanglePro(rect2, origin2, angle2, RED);
	
}
