#pragma once
#include <stdlib.h>
#include <memory>
#include "Vector3.h"
#include "Vector4.h"

class Matrix4x4
{
public:
	Matrix4x4();
	void SetIdentity();
	float& operator()(int x, int y);
	const float& operator()(int x, int y) const;

	Vector4 operator*(const Vector4& right) const;
	Matrix4x4 operator*(const Matrix4x4& right) const;

	void SetTranslation(const Vector3& translation);
	void SetScale(const Vector3& scale);


public:
	float matrix[16];

private:
	//inline float GetElement(int x, int y) const;
	inline const float GetElement(int x, int y) const;
	void SetElement(int x, int y, float value);

};

