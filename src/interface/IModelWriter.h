#pragma once

#include <memory>
#include <vector>
#include <string>
#include "..\model\Triangle.h"


class IModelWriter
{
public:
	virtual bool WriteTriangles(std::vector<Triangle>& triangles, std::string filename) = 0;
};