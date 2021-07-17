#include "Vector4.h"

// Default Constructor
Vector4::Vector4()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
	w = 0.0f;
}
// Variable Set Constructor
Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w)
{
}

Vector4::Vector4(const Vector4& v1)
{
	x = v1.x; y = v1.y; z = v1.z; w = v1.w;
}

// Bool Equals Operator Overload
bool Vector4::operator==(const Vector4& other) const
{
	return (this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
}
// Bool Not Equals Operator Overload
bool Vector4::operator!=(const Vector4& other) const
{
	return !(this->x == other.x && this->y == other.y && this->z == other.z && this->w == other.w);
}
// Addition Operator Overload
Vector4 Vector4::operator+(const Vector4& right) const
{
	return Vector4(this->x + right.x, this->y + right.y, this->z + right.z, this->w + right.w);
}
// Subtraction Operator Overload
Vector4 Vector4::operator-(const Vector4& right) const
{
	return Vector4(this->x - right.x, this->y - right.y, this->z - right.z, this->w - right.w);
}
// Float Multiplication Operator Overload
Vector4 Vector4::operator*(const float& other) const
{
	return Vector4(this->x * other, this->y * other, this->z * other, this->w * other);
}

/*Vector4 Vector4::operator*(const Matrix4x4& other) const
{
	Vector4 result(*this);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			result[i] += vec4[j] * other(i, j);
		}
	}
	return result;
}*/
// Float Division Operator Overload
Vector4 Vector4::operator/(const float& other) const
{
	return Vector4(this->x / other, this->y / other, this->z / other, this->w / other);
}

float Vector4::operator[](int i) const
{
	return vec4[i];
}

float& Vector4::operator[](int i)
{
	return vec4[i];
}
