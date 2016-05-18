#include "circle.hpp"
#include <iostream>
#include <cmath>
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"
#include <utility>

Circle::Circle():
center_{0.0, 0.0},
radius{0},
clr_{0.0} {}

Circle::Circle(float r) :
center_{0.0, 0.0},
radius{r},
clr_{0.0} {}

Circle::Circle(Vec2 const& center, float r, Color const& clr) :
center_{center},
radius{r},
clr_{clr} {}


// member function
bool Circle::operator<(Circle const& c) const
{
	return radius < c.get_radius();
}
bool Circle::operator>(Circle const& c) const
{
	return radius > c.get_radius();
}
bool Circle::operator==(Circle const& c) const
{
	return radius == c.get_radius();
}



// getter
float const& Circle::get_radius() const
{
	return radius;
}
Color const& Circle::get_Color() const
{
	return clr_;
}
Vec2 const& Circle::get_Center() const
{
	return center_;
}

// is_inside
bool Circle::is_inside(Vec2 const& point) const
{
	if (sqrt((point.x - get_Center().x)*(point.x - get_Center().x)
			+(point.y - get_Center().y)*(point.y - get_Center().y)) <= get_radius())
	{
		return true;
	}
	return false;
}

// circumference
float Circle::circumference() const
{
	return 2*M_PI*radius;
}
