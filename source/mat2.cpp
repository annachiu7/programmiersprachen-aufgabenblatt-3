#include "mat2.hpp"
#include <iostream>
#include <math.h>

Mat2::Mat2() :
a{1},
b{0},
c{0},
d{1}
{}

Mat2::Mat2(float a1, float a2, float b1, float b2) :
a{a1},
b{a2},
c{b1},
d{b2}
{}

/////////////////////////////////////////////////////////

Mat2& Mat2::operator *=( Mat2 const & m )
{
	float i = a * m.a + b * m.c;
	float j = a * m.b + b * m.d;
	float k = c * m.a + d * m.c;
	float l = c * m.b + d * m.d;
	a = i;
	b = j;
	c = k;
	d = l;
	return *this;
}

////////////////////////////////////////////////////////

Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 )
{
	return Mat2{m1.a * m2.a + m1.b * m2.c, 
				m1.a * m2.b + m1.b * m2.d, 
				m1.c * m2.a + m1.d * m2.c,
				m1.c * m2.b + m1.d * m2.d};
}

////////////////////////////////////////////////////////

float Mat2::det() const
{
	return a*d - b*c;
}

Vec2 operator *( Mat2 const & m , Vec2 const & v )
{
	return Vec2{m.a * v.x + m.b * v.y,
				m.c * v.x + m.d * v.y};
}

Vec2 operator *( Vec2 const & v , Mat2 const & m )
{
	return Vec2{v.x * m.a + v.y * m.c,
				v.x * m.b + v.y * m.d};
}

Mat2 inverse(Mat2 const& m)
{

	if(m.a * m.d - m.b * m.c == 0)
	{
		// wenn der Derterminant gleich 0 ist, gibt es keine Inverse!
		return Mat2{0,0,0,0};
	}
	else	
	{	
		float a = m.d / ( m.a * m.d - m.b * m.c );
		float b = -m.b / ( m.a * m.d - m.b * m.c );
		float c = -m.c / ( m.a * m.d - m.b * m.c );
		float d = m.a / ( m.a * m.d - m.b * m.c );
		return Mat2{a,b,c,d};
	}
}

Mat2 transpose(Mat2 const& m)
{
	return Mat2{m.a,m.c,m.b,m.d};
}

Mat2 make_rotation_mat2(float phi)
{
	float a = cos(phi);
	float b = -sin(phi);
	float c = sin(phi);
	float d = cos(phi);
	return Mat2{a,b,c,d};
}
