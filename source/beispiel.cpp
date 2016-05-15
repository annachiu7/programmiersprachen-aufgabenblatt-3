#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>

int main()
{
	std::vector<int> v0(10);
	for (std::vector<int>::iterator it = v0.begin();
		it != v0.end(); ++it)
	{
		*it = std::rand();
	}
	std::copy( std::begin(v0), std::end(v0), std::ostream_iterator <int> (std::cout, "\n") );


	std::list <int> l0( v0.size() );  // create a list with the size of v0
	std::copy( std::begin(v0), std::end(v0), std::begin(l0) );  // copy every block from v0 to l0

	std::list <int> l1( std::begin(l0), std::end(l0) );  // create a list with the size of l0
	std::reverse( std::begin(l1), std::end(l1) );  // reverse l1
	std::copy( std::begin(l1), std::end(l1), std::ostream_iterator <int> (std::cout,"\n") );
	
	l1.sort();
	std::copy( l1.begin(), l1.end(), std::ostream_iterator <int> (std::cout,"\n") );  // output sorted l1
	std::generate( std::begin(v0), std::end(v0), std::rand );  // generate random numbers to every block of v0
	std::copy( v0.rbegin(), v0.rend(), std::ostream_iterator <int> (std::cout,"\n") );  // output reversed v0 (rbegin,rend: reversed iterator)
	
	return 0;
}