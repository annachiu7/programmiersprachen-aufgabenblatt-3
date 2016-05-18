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
#include <functional>
#include "filter.hpp"

int randNum()
{
	return std::rand()%101;
}

bool is_even(int a)
{
	return (a%2)==0;
}

template<typename T>
void swap_(T & a, T & b) // & no copie, otherwise values dont change
{
	T c = a;
	a = b;
	b = c;
}

/*
void swap_(int *a, int *b)
{
	int c=*a;
	*a=*b;
	*b=t;
}
*/

TEST_CASE("describe_factorial", "[aufgabe3]")
{
	std::vector<unsigned int> v(100);
	std::generate( std::begin(v), std::end(v), randNum );
	std::vector<unsigned int>::iterator bound = std::partition(v.begin(), v.end(), is_even); // first part even, second odd
	v.erase(bound, v.end());
	
	REQUIRE(std::all_of(v.begin(),v.end(), is_even));
}

TEST_CASE("describe_sorted_circle", "[aufgabe3.7]")
{
	std::set<Circle> s;
	for (float i = 15.0f; i > 5.0f; --i)
	{
		s.insert(Circle{i});
	}
	
	REQUIRE(std::is_sorted(s.begin(),s.end()));
}

TEST_CASE("describe_swap", "[aufgabe3.8]")
{
	int a = 3;	int b = 5;
	swap_(a,b);
	REQUIRE(b == 3);
	REQUIRE(a == 5);

	Circle c1{1.0}; Circle c2{2.0};
	swap_(c1,c2);
	REQUIRE(c1.get_radius()==2.0);
	REQUIRE(c2.get_radius()==1.0);
}

TEST_CASE("describe_sorted_circle_lambda", "[aufgabe3.9]")
{
	std::vector<Circle> v{Circle{0.3}, Circle{5.0}, Circle{3.2}, Circle{1.0}};
	std::sort(v.begin(), v.end(),
				[](Circle const& i, Circle const& j)
				  { 
				  	return i<j; 
				  });
	REQUIRE(std::is_sorted(v.begin(),v.end()));
}


TEST_CASE("describe_add_vector_containers", "[aufgabe3.10]")
{
	std::vector<int> v1{1,2,3,4,5,6,7,8,9};
	std::vector<int> v2{9,8,7,6,5,4,3,2,1};
	std::vector<int> v3(9);
	std::transform(v1.begin(),v1.end(),v2.begin(),v3.begin(),
				   [](int i, int j)
				   {
				   	 return i + j;
				   } );
	REQUIRE(std::all_of(v3.begin(), v3.end(), 
						[](int i)
						{
							return i==10;
						}));

}

TEST_CASE("describe_filter", "[aufgabe3.11]")
{
	std::vector<int> v {1, 2, 3, 4, 5, 6};
	std::vector<int> alleven = filter(v, is_even);
	REQUIRE(std::all_of( alleven.begin(), alleven.end(), 
						 [](int a)
						 {
						 	return (a%2)==0;
						 } ));
}

TEST_CASE("describe_3.13", "[aufgabe3.13]")
{
	std::vector<Circle> circles{Circle{5.0f},Circle{3.0f},Circle{8.0f},Circle{1.0f},Circle{5.0f}};
	std::vector<Circle> result(circles.size());
	std::copy_if(circles.begin(),circles.end(),result.begin(),
				 [](Circle const& c)
				 {
				 	return c.get_radius()>=4.0f;
				 });

	auto it = result.end()-1;
	while (*it == Circle{})
	{
		result.pop_back();
		it = result.end()-1;
	}

	REQUIRE(result.size()==3);
	REQUIRE(std::all_of(result.begin(), result.end(), 
						[](Circle const& c)
						{
							return c.get_radius()>=3.0f;
						}));
}

template<typename T>
class sort_C 
{
public:
	bool operator() (T const& i, T const& j)
	{
		return i<j;
	}
};

TEST_CASE("describe_sorted_circle_lambda_3.14", "[aufgabe3.14]")
{
	sort_C<Circle> sort_circle;
	std::vector<Circle> v{Circle{0.3}, Circle{5.0}, Circle{3.2}, Circle{1.0}};
	std::sort(v.begin(), v.end(),sort_circle);
	REQUIRE(std::is_sorted(v.begin(),v.end()));
}




int main(int argc, char *argv[])
{
	return Catch::Session().run(argc, argv);
}