#include "vec2.hpp"
#include <iostream>

Vec2::Vec2() :
x{0.0f},
y{0.0f}
{}

Vec2::Vec2(float a, float b) :
x{a},
y{b}
{}

////////////////////////////////////////////////////////////

Vec2& Vec2::operator+=(Vec2 const& v) 
{
	x += v.x;
	y += v.y;
	return *this;
}

Vec2& Vec2::operator-=(Vec2 const& v) 
{
	x -= v.x;
	y -= v.y;
	return *this;
}

Vec2& Vec2::operator*=(float v) 
{
	x *= v;
	y *= v;
	return *this;
}

Vec2& Vec2::operator/=(float v) 
{
	x /= v;
	y /= v;
	return *this;
}

///////////////////////////////////////////////////////////

Vec2 operator+(Vec2 const& u, Vec2 const& v)
{
	return Vec2{u.x + v.x, u.y + v.y};
}

Vec2 operator-(Vec2 const& u, Vec2 const& v)
{
	return Vec2{u.x - v.x, u.y - v.y};
}

Vec2 operator*(Vec2 const& v, float s)
{
	return Vec2{v.x * s, v.y * s};
}

Vec2 operator/(Vec2 const& v, float s)
{
	return Vec2{v.x / s, v.y / s};
}

Vec2 operator*(float s, Vec2 const& v)
{
	return Vec2{v.x * s, v.y * s};
}