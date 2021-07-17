#include "Vector3.h"

// Default Constructor
Vector3::Vector3()
{
	x = 0.0f;
	y = 0.0f;
	z = 0.0f;
}
// Variable Set Constructor
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z)
{
}

Vector3::Vector3(const Vector3& v1)
{ 
	x = v1.x; y = v1.y; z = v1.z;
}

// Bool Equals Operator Overload
bool Vector3::operator==(const Vector3& other) const
{
	return (this->x == other.x && this->y == other.y && this->z == other.z);
}
// Bool Not Equals Operator Overload
bool Vector3::operator!=(const Vector3& other) const
{
	return !(this->x == other.x && this->y == other.y && this->z == other.z);
}
// Addition Operator Overload
Vector3 Vector3::operator+(const Vector3& right) const
{
	return Vector3(this->x + right.x, this->y + right.y, this->z + right.z);
}
// Subtraction Operator Overload
Vector3 Vector3::operator-(const Vector3& right) const
{
	return Vector3(this->x - right.x, this->y - right.y, this->z - right.z);
}
// Float Multiplication Operator Overload
Vector3 Vector3::operator*(const float& other) const
{
	return Vector3(this->x * other, this->y * other, this->z * other);
}
// Float Division Operator Overload
Vector3 Vector3::operator/(const float& other) const
{
	return Vector3(this->x / other, this->y / other, this->z / other);
}

float Vector3::operator[](int i) const
{
	return vec3[i];
}

float& Vector3::operator[](int i)
{
	return vec3[i];
}
