#include "Domain/Math/Vector4.h"
#include "Domain/Type.h"

Vector4::Vector4()
	: X(0.0f)
	, Y(0.0f)
	, Z(0.0f)
	, W(0.0f)
{
}

Vector4::Vector4(const sf4 x, const sf4 y, const sf4 z, const sf4 w)
	: X(x)
	, Y(y)
	, Z(z)
	, W(w)
{
}

Vector4 Vector4::operator + (const Vector4& other) const
{
	return { X + other.X, Y + other.Y, Z + other.Z, W + other.W };
}

Vector4 Vector4::operator - (const Vector4& other) const
{
	return { X - other.X, Y - other.Y, Z - other.Z, W - other.W };
}

Vector4 Vector4::operator * (const sf4 other) const
{
	return { X * other, Y * other, Z * other, W * other };
}

Vector4 Vector4::operator / (const sf4 other) const
{
	return { X / other, Y / other, Z / other, W / other };
}

Vector4Int::Vector4Int()
	: X(0)
	, Y(0)
	, Z(0)
	, W(0)
{
}

Vector4Int::Vector4Int(const si4 x, const si4 y, const si4 z, const si4 w)
	: X(x)
	, Y(y)
	, Z(z)
	, W(w)
{
}

Vector4Int Vector4Int::operator + (const Vector4Int& other) const
{
	return { X + other.X, Y + other.Y, Z + other.Z, W + other.W };
}

Vector4Int Vector4Int::operator - (const Vector4Int& other) const
{
	return { X - other.X, Y - other.Y, Z - other.Z, W - other.W };
}

Vector4Int Vector4Int::operator*(const si4 other) const
{
	return { X * other, Y * other, Z * other, W * other };
}

Vector4Int Vector4Int::operator/(const si4 other) const
{
	return { X / other, Y / other, Z / other, W / other };
}
