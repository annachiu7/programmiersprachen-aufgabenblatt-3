#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "color.hpp"
#include "mat2.hpp"
#include "vec2.hpp"

class Circle
{
public:
	Circle(float r);
	// Circle(Circle const& c);
	// Circle(Circle&& c);
	Circle(Vec2 const& center, float r, Color const& clr);

	// member function
	bool operator<(Circle const& c) const;
	bool operator>(Circle const& c) const;
	bool operator==(Circle const& c) const;

	//getter
	float const& get_radius() const;
	Color const& get_Color() const;
	Vec2 const& get_Center() const;

	// other function
	bool is_inside(Vec2 const& point) const;
	float circumference() const;

private:
	// member
	Vec2 center_;
	float radius;
	Color clr_;
};


#endif 