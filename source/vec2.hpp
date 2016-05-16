#ifndef VEC2_HPP
#define VEC2_HPP

// Vec2 class definition
class Vec2
{
public:
	Vec2();  // default constructor
	Vec2(float a, float b); // user constructors

	float x;
	float y;

	//member function
	Vec2& operator+=(Vec2 const& v);
	Vec2& operator-=(Vec2 const& v);
	Vec2& operator*=(float v);
	Vec2& operator/=(float v);


};


Vec2 operator+(Vec2 const& u, Vec2 const& v);
Vec2 operator-(Vec2 const& u, Vec2 const& v);
Vec2 operator*(Vec2 const& v, float s);
Vec2 operator/(Vec2 const& v, float s);
Vec2 operator*(float s, Vec2 const& v);

#endif // VEC2_HPP