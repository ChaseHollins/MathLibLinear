#include "Transform.h"
#include "sfwdraw.h"

Transform::Transform(float x, float y,
	float w, float h, float a)
{
	position.x = x;
	position.y = y;

	scale.x = w;
	scale.y = h;

	facing = a;
}

vec2 Transform::getUp() const
{
	return -perp(getDirection());
}

// to the right.
vec2 Transform::getDirection() const
{
	return fromAngle(facing);
}

void Transform::setDirection(const vec2 &dir)
{
	facing = angle(dir);
}

void Transform::debugDraw() const
{
	sfw::drawCircle(position.x,
					position.y, 12,12, 0x888888FF);

	vec2 dirEnd = position + getDirection() * scale.x * 4;
	vec2 upEnd = position - perp(getDirection()) * scale.y * 4;

	sfw::drawLine(position.x, position.y,
				    dirEnd.x,   dirEnd.y, RED);

	sfw::drawLine(position.x, position.y,
					upEnd.x, upEnd.y, GREEN);
}
