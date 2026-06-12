#include "Ball.h"

Ball::Ball(b2World& _world, float _x, float _y, float _r, Color _c)
{
	radius = _r;
	color = _c;

	b2BodyDef bodyDef;
	bodyDef.type = b2_dynamicBody;
	bodyDef.position.Set(_x, _y);

	bodyDef.bullet = true;

	ballBody = _world.CreateBody(&bodyDef);

	b2CircleShape circleShape;
	circleShape.m_radius = radius;

	b2FixtureDef fixtureDef;
	fixtureDef.shape = &circleShape;
	fixtureDef.density = 0.01f;
	fixtureDef.friction = 0.05f;
	fixtureDef.restitution = 1.0f;

	ballBody->CreateFixture(&fixtureDef);

}

void Ball::Draw()
{
	b2Vec2 pos = ballBody->GetPosition();

	DrawCircle(pos.x, pos.y, radius, color);
}