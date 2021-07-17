#pragma once
struct Vector2
{
	Vector2();
	Vector2(float x, float y);
	~Vector2();

	Vector2(const Vector2& v1);

	// Bool Equals Operator Overload
	bool operator==(const Vector2& other) const;
	// Bool Not Equals Operator Overload
	bool operator!=(const Vector2& other) const;
	// Addition Operator Overload
	Vector2 operator+(const Vector2& right) const;
	// Subtraction Operator Overload
	Vector2 operator-(const Vector2& right) const;
	// Float Multiplication Operator Overload
	Vector2 operator*(const float& other) const;

	float x, y;

};

