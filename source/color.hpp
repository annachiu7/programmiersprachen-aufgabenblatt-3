#ifndef COLOR_HPP
#define COLOR_HPP

struct Color
{

	float r;
	float g;
	float b;

	Color(float f)
	{
		r=f;
		g=f;
		b=f;
		if (f>1) { r=1;g=1;b=1; }
	};
	Color(float x, float y, float z)
	{
		r=x;
		g=y;
		b=z;
		if (x>1) {r=1;}
		if (y>1) {g=1;}
		if (z>1) {b=1;}
	};


};


#endif 