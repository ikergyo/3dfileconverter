#pragma once
struct Vector3
{
	// Default Constructor
	Vector3();
	// Variable Set Constructor
	Vector3(float x, float y, float z);

	Vector3(const Vector3& v1);

	// Bool Equals Operator Overload
	bool operator==(const Vector3& other) const;
	// Bool Not Equals Operator Overload
	bool operator!=(const Vector3& other) const;
	// Addition Operator Overload
	Vector3 operator+(const Vector3& right) const;
	// Subtraction Operator Overload
	Vector3 operator-(const Vector3& right) const;
	// Float Multiplication Operator Overload
	Vector3 operator*(const float& other) const;
	// Float Division Operator Overload
	Vector3 operator/(const float& other) const;

	float operator[](int i) const;
	float& operator[](int i);

	union
	{
		struct
		{
			float x, y, z;
		};
		float vec3[3];
	};
};

