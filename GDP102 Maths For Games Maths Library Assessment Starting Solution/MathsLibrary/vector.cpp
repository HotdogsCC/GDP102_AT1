#include "vector.h"

//Vector 2

//Constructors
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

//Assignment
Vector2& Vector2::operator = (const Vector2& other)
{
	x = other.x;
	y = other.y;
}

//Indexing Operators
float Vector2::operator [] (int index) const
{
	return data[index];
}
float& Vector2::operator [] (int index)
{
	return data[index];
}

//Dot product
float Vector2::dot(const Vector2& other) const
{
	return { x * other.x + y * other.y };
}

//Angle between
float Vector2::angleBetween(const Vector2& other) const
{
	std::cout << "my man, you totally forgot to add this. fix it up g";
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