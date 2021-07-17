#pragma once
#include <vector>
#include "Vertex.h"

struct Triangle
{
	Triangle();
	Triangle(std::vector<Vertex> vertices);
	~Triangle();
	std::vector<Vertex> vertices;
	Vector3 normal;
	float GetSurfaceArea() const;
	float GetSignedVolume() const;
private:
	void GetNormal();
};

