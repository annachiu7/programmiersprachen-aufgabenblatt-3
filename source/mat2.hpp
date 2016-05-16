#ifndef MAT2_HPP
#define MAT2_HPP
#include "vec2.hpp"

// Mat2 class definition
class Mat2
{
public:
	Mat2();  // default constructor
	Mat2(float a1, float a2, float b1, float b2);  // user constructor

	float a;
	float b;
	float c;
	float d;

	float det() const;

	Mat2& operator *=( Mat2 const & m );

};

Mat2 operator *( Mat2 const & m1 , Mat2 const & m2 );

//Aufgabe 2.6
Vec2 operator *( Mat2 const & m , Vec2 const & v );
Vec2 operator *( Vec2 const & v , Mat2 const & m );
Mat2 inverse(Mat2 const& m);
Mat2 transpose(Mat2 const& m);
Mat2 make_rotation_mat2(float phi);

#endif