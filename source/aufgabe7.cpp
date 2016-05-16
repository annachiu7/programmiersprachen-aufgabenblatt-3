#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>
#include <set>
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

TEST_CASE("describe_sorted_circle", "[aufgabe3.7]")
{
	std::set<Circle> s;
	for (int i = 15; i > 5; --i)
	{
		s.insert(Circle{i});
	}
	
	REQUIRE(std::is_sorted(s.begin(),s.end()));
}

TEST_CASE("describe_swap", "[aufgabe3.8]")
{
	int a = 3;	int b = 5;
	swap(a,b);
	REQUIRE(b == 3);
}


int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}