#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>
#include <iostream>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"

template<typename T>
void swap(T & a, T & b) // & no copie, otherwise values dont change
{
	T c = a;
	a = b;
	b = c;
}

/*
void swap(int *a, int *b)
{
	int c=*a;
	*a=*b;
	*b=t;
}
*/


TEST_CASE("describe_swap", "[aufgabe3.8]")
{
	int a = 3;	int b = 5;
	swap(a,b);
	REQUIRE(b == 3);
	REQUIRE(a == 5);

	Circle c1{1.0}; Circle c2{2.0};
	swap(c1,c2);
	REQUIRE(c1.get_radius()==2.0);
	REQUIRE(c2.get_radius()==1.0);
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}

