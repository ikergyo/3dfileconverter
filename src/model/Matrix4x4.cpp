#include "Matrix4x4.h"

Matrix4x4::Matrix4x4()
{
	std::memset(matrix, 0, sizeof(float) * 16);
}
void Matrix4x4::SetIdentity()
{
	//std::memset(matrix, 0, sizeof(float) * 16);
	for (int i = 0; i < 4; i++)
	{
		SetElement(i, i, 1);
	}
}
void Matrix4x4::SetTranslation(const Vector3& translation)
{
	SetIdentity();
	SetElement(0, 3, translation.x);
	SetElement(1, 3, translation.y);
	SetElement(2, 3, translation.z);
}
void  Matrix4x4::SetScale(const Vector3& scale)
{
	SetIdentity();
	for (int i = 0; i < 3; i++)
	{
		SetElement(i, i, scale[i]);
	}
}



float& Matrix4x4::operator()(int x, int y)
{
	return matrix[y * 4 + x];
}
const float& Matrix4x4::operator()(int x, int y) const
{
	return GetElement(x, y);
}

Vector4 Matrix4x4::operator*(const Vector4& right) const
{
	Vector4 result;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i] += GetElement(i, j) * right[j];
		}
	}
	return result;
}

Matrix4x4 Matrix4x4::operator*(const Matrix4x4& right) const
{
	Matrix4x4 result;
	
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			for (int k = 0; k < 4; k++)
			{
				result(i, j) += GetElement(i, k) * right(k, j);
			}
			
		}
	}
	return result;
}

/*inline float Matrix4x4::GetElement(int x, int y) const
{
	return matrix[y * 4 + x];
}*/
inline const float Matrix4x4::GetElement(int x, int y) const
{
	return matrix[y * 4 + x];
}
void Matrix4x4::SetElement(int x, int y, float value)
{
	matrix[y * 4 + x] = value;
}