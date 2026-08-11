#pragma once

#include "Domain/Type.h"

struct Vector3
{
public:
	sf4 X;
	sf4 Y;
	sf4 Z;

	Vector3();
	Vector3(const sf4 x, const sf4 y, const sf4 z);

	Vector3 operator + (const Vector3& other) const;
	Vector3 operator - (const Vector3& other) const;
	Vector3 operator * (const sf4 other) const;
	Vector3 operator / (const sf4 other) const;
};

struct Vector3Int
{
public:
	si4 X;
	si4 Y;
	si4 Z;

	Vector3Int();
	Vector3Int(const si4 x, const si4 y, const si4 z);

	Vector3Int operator + (const Vector3Int& other) const;
	Vector3Int operator - (const Vector3Int& other) const;
	Vector3Int operator * (const si4 other) const;
	Vector3Int operator / (const si4 other) const;
};
