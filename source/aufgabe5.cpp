#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <cmath>
#include <algorithm>
#include <vector>
#include <iostream>
#include <iterator>

int randNum()
{
	return std::rand()%101;
}

bool is_even(int a)
{
	return (a%2)==0;
}

TEST_CASE("describe_factorial", "[aufgabe3]")
{
	std::vector<unsigned int> v(100);
	std::generate( std::begin(v), std::end(v), randNum );
	std::vector<unsigned int>::iterator bound = std::partition(v.begin(), v.end(), is_even); // first part even, second odd
	v.erase(bound, v.end());
	
	REQUIRE(std::all_of(v.begin(),v.end(), is_even));
}

int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}