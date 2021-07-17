#pragma once
#include "..\model\Vector3.h"
#include "..\model\Triangle.h"
#include "..\model\Matrix4x4.h"
#include "..\model\Vector4.h"
#include <vector>
#include <numeric>

class ModelCalculator
{
public:
	static float GetSurfaceArea(const std::vector<Triangle>& triangles);
	static float GetVolume(const std::vector<Triangle>& triangles);
	static bool IsPointInsideTheModel(const Vector3& point, const std::vector<Triangle>& triangles);
	static void SetTranformation(std::vector<Triangle>& triangles, Matrix4x4& transformation);
private:
	ModelCalculator();
};

