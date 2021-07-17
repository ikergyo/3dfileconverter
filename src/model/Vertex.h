#pragma once
#include "Vector2.h"
#include "Vector3.h"

struct Vertex
{
	Vertex();

	// Position Vector
	Vector3 Position;

	// Texture Coordinate Vector
	Vector2 TextureCoordinate;

	// Normal Vector
	Vector3 Normal;
};

