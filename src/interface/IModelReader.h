#pragma once
#include <memory>
#include <vector>
#include <string>
#include "..\model\Triangle.h"

class IModelReader
{
public:
	virtual std::vector<Triangle> ReadTriangles(std::string filename) = 0;
};