#include "ModelCalculator.h"

ModelCalculator::ModelCalculator(){}


float ModelCalculator::GetSurfaceArea(const std::vector<Triangle>& triangles)
{
	float sum = 0;
	for (int i = 0; i < triangles.size(); i++)
	{
		sum += triangles[i].GetSurfaceArea();
	}
	return sum;
}

float ModelCalculator::GetVolume(const std::vector<Triangle>& triangles)
{
	float sum = 0;
	for (int i = 0; i < triangles.size(); i++)
	{
		sum += triangles[i].GetSignedVolume();
	}
	return abs(sum);
}
/// <summary>
/// Checks, the point is inside or outside of the model
/// </summary>
/// <param name="point">Point for checking</param>
/// <param name="triangles">Reference for the triangles</param>
/// <returns>True if the point is inside the model</returns>
bool ModelCalculator::IsPointInsideTheModel(const Vector3& point, const std::vector<Triangle>& triangles)
{
	//std::vector<float> pointV = { point.x, point.y, point.z };
	for (int i = 0; i < triangles.size(); i++)
	{
		std::vector<float> triangleNormal = { triangles[i].normal.x, triangles[i].normal.y, triangles[i].normal.z };
		Vector3 middleOfTriangle(
			(triangles[i].vertices[0].Position.x + triangles[i].vertices[1].Position.x + triangles[i].vertices[2].Position.x) / 3.0f,
			(triangles[i].vertices[0].Position.y + triangles[i].vertices[1].Position.y + triangles[i].vertices[2].Position.y) / 3.0f,
			(triangles[i].vertices[0].Position.z + triangles[i].vertices[1].Position.z + triangles[i].vertices[2].Position.z) / 3.0f
		);
		Vector3 pointTNorm = middleOfTriangle - point;
		std::vector<float> pointV = { pointTNorm.x, pointTNorm.y, pointTNorm.z };

		float dotResult = std::inner_product(pointV.begin(), pointV.end(), triangleNormal.begin(), 0.0f);
		if (dotResult < 0)
			return false;
	}
	return true;
}

void ModelCalculator::SetTranformation(std::vector<Triangle>& triangles, Matrix4x4& transformation)
{
	for (int i = 0; i < triangles.size(); i++)
	{
		for (int j = 0; j < triangles[i].vertices.size(); j++)
		{
			Vector4 pos = Vector4(triangles[i].vertices[j].Position.x, triangles[i].vertices[j].Position.y, triangles[i].vertices[j].Position.z, 1);
			Vector4 dir = Vector4(triangles[i].vertices[j].Normal.x, triangles[i].vertices[j].Normal.y, triangles[i].vertices[j].Normal.z, 0);

			pos = transformation * pos;
			dir = transformation * dir;

			triangles[i].vertices[j].Position = Vector3(pos.x / pos.w, pos.y / pos.w, pos.z / pos.w);
			triangles[i].vertices[j].Normal = Vector3(dir.x, dir.y, dir.z);
		}		
	}
}