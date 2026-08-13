#include "Domain/Math/Vector2.h"
#include "Domain/Type.h"

Vector2::Vector2()
	: X(0.0f)
	, Y(0.0f)
{
}

Vector2::Vector2(const sf4 x, const sf4 y)
	: X(x)
	, Y(y)
{
}

Vector2 Vector2::operator + (const Vector2& other) const
{
	return { X + other.X, Y + other.Y };
}

Vector2 Vector2::operator - (const Vector2& other) const
{
	return { X - other.X, Y - other.Y };
}

Vector2 Vector2::operator * (const sf4 other) const
{
	return { X * other, Y * other };
}

Vector2 Vector2::operator / (const sf4 other) const
{
	return { X / other, Y / other };
}

Vector2Int::Vector2Int()
	: X(0)
	, Y(0)
{
}

Vector2Int::Vector2Int(const si4 x, const si4 y)
	: X(x)
	, Y(y)
{
}

Vector2Int Vector2Int::operator+(const Vector2Int& other) const
{
	return { X + other.X, Y + other.Y };
}

Vector2Int Vector2Int::operator-(const Vector2Int& other) const
{
	return { X - other.X, Y - other.Y };
}

Vector2Int Vector2Int::operator*(const si4 other) const
{
	return { X * other, Y * other };
}

Vector2Int Vector2Int::operator/(const si4 other) const
{
	return { X / other, Y / other };
}
