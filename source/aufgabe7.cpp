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


TEST_CASE("describe_sorted_circle", "[aufgabe3.7]")
{
	std::set<Circle> s;
	for (int i = 15; i > 5; --i)
	{
		s.insert(Circle{i});
	}
	
	REQUIRE(std::is_sorted(s.begin(),s.end()));
}


int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}