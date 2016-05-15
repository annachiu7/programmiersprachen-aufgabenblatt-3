#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>


// random-number-generator from 0 to 100
int randNum()
{
	return std::rand()%101;
}


int main()
{
	std::list<unsigned int> l0(100);  // unsigned int: int without - or +, start from 0
	std::generate( std::begin(l0), std::end(l0), randNum );
	std::copy( std::begin(l0), std::end(l0), std::ostream_iterator <int> (std::cout, "\n") );
	
	std::vector<unsigned int> v0(100);
	std::copy( std::begin(l0), std::end(l0), std::begin(v0) );
	std::copy( std::begin(v0), std::end(v0), std::ostream_iterator <int> (std::cout, "\n") );
}