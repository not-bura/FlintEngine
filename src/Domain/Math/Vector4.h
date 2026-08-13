#pragma once

#include "Domain/Type.h"

struct Vector4
{
public:
	sf4 X;
	sf4 Y;
	sf4 Z;
	sf4 W;

	Vector4();
	Vector4(const sf4 x, const sf4 y, const sf4 z, const sf4 w);

	Vector4 operator + (const Vector4& other) const;
	Vector4 operator - (const Vector4& other) const;
	Vector4 operator * (const sf4 other) const;
	Vector4 operator / (const sf4 other) const;
};

struct Vector4Int
{
public:
	si4 X;
	si4 Y;
	si4 Z;
	si4 W;

	Vector4Int();
	Vector4Int(const si4 x, const si4 y, const si4 z, const si4 w);

	Vector4Int operator + (const Vector4Int& other) const;
	Vector4Int operator - (const Vector4Int& other) const;
	Vector4Int operator * (const si4 other) const;
	Vector4Int operator / (const si4 other) const;
};
