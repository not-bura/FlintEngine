#pragma once

#include "Domain/Type.h"

struct Vector2
{
public:
	sf4 X;
	sf4 Y;

	Vector2();
	Vector2(const sf4 x, const sf4 y);

	Vector2 operator + (const Vector2& other) const;
	Vector2 operator - (const Vector2& other) const;
	Vector2 operator * (const sf4 other) const;
	Vector2 operator / (const sf4 other) const;
};

struct Vector2Int
{
public:
	si4 X;
	si4 Y;

	Vector2Int();
	Vector2Int(const si4 x, const si4 y);

	Vector2Int operator + (const Vector2Int& other) const;
	Vector2Int operator - (const Vector2Int& other) const;
	Vector2Int operator * (const si4 other) const;
	Vector2Int operator / (const si4 other) const;
};
