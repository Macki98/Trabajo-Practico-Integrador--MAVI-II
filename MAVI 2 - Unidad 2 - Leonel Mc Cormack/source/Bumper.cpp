#include "Bumper.h"

Bumper::Bumper(b2World& _world, float _x, float _y, float _r)
{
	radius = _r;
	color = BLUE;

	b2BodyDef bodyDef;
	bodyDef.type = b2_staticBody;
	bodyDef.position.Set(_x, _y);
	bumperBody = _world.CreateBody(&bodyDef);

	b2CircleShape bumperShape;
	bumperShape.m_radius = radius;

	b2FixtureDef bumperFixture;
	bumperFixture.shape = &bumperShape;
	bumperFixture.density = 0.0f;
	bumperFixture.friction = 0.2f;
	bumperFixture.restitution = 1.5f;

	bumperBody->CreateFixture(&bumperFixture);

}

void Bumper::Draw()
{
	b2Vec2 pos = bumperBody->GetPosition();

	DrawCircle(pos.x, pos.y, radius, color);

	DrawCircle(pos.x, pos.y, radius * 0.4f, RED);
}
