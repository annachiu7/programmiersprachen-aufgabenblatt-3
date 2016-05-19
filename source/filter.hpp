#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <vector>
#include <iostream>
#include <algorithm>
#include "circle.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "color.hpp"

template<typename Container, typename Functor>
Container filter(Container const& container, Functor const& predicate)
{
		Container res{};
		for(auto&& value: container) //access by reference, the type of value is auto&
			{ 
			if (predicate(value))
			{
				res.push_back(value);
			}
		}
		return res;
}