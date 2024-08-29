#include "vector.h"
//#include "pch.h"

Vector2::Vector2()
{
	x = 0;
	y = 0;
}
Vector2::Vector2(float _x, float _y)
{
	x = _x;
	y = _y;
}
Vector2::Vector2(const Vector2& other)
{
	x = other.x;
	y = other.y;
}

float Vector2::operator [] (int index) const
{
	return data[index];
}

Vector2 Vector2::operator + (const Vector2& other) const
{
	return { x + other.x, y + other.y };
}

Vector2& Vector2::operator += (const Vector2& other)
{
	x += other.x;
	y += other.y;
	return *this;
}

Vector2& Vector2::operator -= (const Vector2& other)
{
	x -= other.x;
	y -= other.y;
	return *this;
}