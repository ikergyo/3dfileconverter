#pragma once


struct Vector4
{
	// Default Constructor
	Vector4();
	// Variable Set Constructor
	Vector4(float x, float y, float z, float w);

	Vector4(const Vector4& v1);

	// Bool Equals Operator Overload
	bool operator==(const Vector4& other) const;
	// Bool Not Equals Operator Overload
	bool operator!=(const Vector4& other) const;
	// Addition Operator Overload
	Vector4 operator+(const Vector4& right) const;
	// Subtraction Operator Overload
	Vector4 operator-(const Vector4& right) const;
	// Float Multiplication Operator Overload
	Vector4 operator*(const float& other) const;

	//Vector4 operator*(const Matrix4x4& other) const;

	// Float Division Operator Overload
	Vector4 operator/(const float& other) const;

	float operator[](int i) const;
	float& operator[](int i);


	union
	{
		struct 
		{
			float x, y, z, w;
		};
		float vec4[4];
	};
};

