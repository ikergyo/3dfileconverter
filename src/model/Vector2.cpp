#include "Vector2.h"


Vector2::Vector2()
{
	x = 0.0f;
	y = 0.0f;
}
Vector2::Vector2(float x, float y) : x(x), y(y)
{

}
Vector2::~Vector2() 
{

}

Vector2::Vector2(const Vector2& v1)
{ 
	x = v1.x; y = v1.y; 
}

// Bool Equals Operator Overload
bool Vector2::operator==(const Vector2& other) const
{
	return (this->x == other.x && this->y == other.y);
}
// Bool Not Equals Operator Overload
bool Vector2::operator!=(const Vector2& other) const
{
	return !(this->x == other.x && this->y == other.y);
}
// Addition Operator Overload
Vector2 Vector2::operator+(const Vector2& right) const
{
	return Vector2(this->x + right.x, this->y + right.y);
}
// Subtraction Operator Overload
Vector2 Vector2::operator-(const Vector2& right) const
{
	return Vector2(this->x - right.x, this->y - right.y);
}
// Float Multiplication Operator Overload
Vector2 Vector2::operator*(const float& other) const
{
	return Vector2(this->x * other, this->y * other);
}