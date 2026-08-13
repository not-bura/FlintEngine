#include "Domain/Math/Vector3.h"
#include "Domain/Type.h"

Vector3::Vector3()
	: X(0.0f)
	, Y(0.0f)
	, Z(0.0f)
{
}

Vector3::Vector3(const sf4 x, const sf4 y, const sf4 z)
	: X(x)
	, Y(y)
	, Z(z)
{
}

Vector3 Vector3::operator + (const Vector3& other) const
{
	return Vector3{ X + other.X, Y + other.Y, Z + other.Z };
}

Vector3 Vector3::operator - (const Vector3& other) const
{
	return Vector3{ X - other.X, Y - other.Y, Z - other.Z };
}

Vector3 Vector3::operator * (const sf4 other) const
{
	return Vector3{ X * other, Y * other, Z * other };
}

Vector3 Vector3::operator / (const sf4 other) const
{
	return Vector3{ X / other, Y / other, Z / other };
}

Vector3Int::Vector3Int()
	: X(0)
	, Y(0)
	, Z(0)
{
}

Vector3Int::Vector3Int(const si4 x, const si4 y, const si4 z)
	: X(x)
	, Y(y)
	, Z(z)
{
}

Vector3Int Vector3Int::operator + (const Vector3Int& other) const
{
	return Vector3Int{ X + other.X, Y + other.Y, Z + other.Z };
}

Vector3Int Vector3Int::operator - (const Vector3Int& other) const
{
	return Vector3Int{ X - other.X, Y - other.Y, Z - other.Z };
}

Vector3Int Vector3Int::operator * (const si4 other) const
{
	return Vector3Int{ X * other, Y * other, Z * other };
}

Vector3Int Vector3Int::operator / (const si4 other) const
{
	return Vector3Int{ X / other, Y / other, Z / other };
}
