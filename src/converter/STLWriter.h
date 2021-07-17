#pragma once
#include "../interface/IModelWriter.h"


class STLWriter : IModelWriter
{
public:
	bool WriteTriangles(std::vector<Triangle>& triangles, std::string filename);
};

