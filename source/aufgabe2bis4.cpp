#include <cstdlib>
#include <vector>
#include <list>
#include <iostream>
#include <iterator>
#include <algorithm>
#include <set>
#include <map>


// random-number-generator from 0 to 100
int randNum()
{
	return std::rand()%101;
}


int main()
{
	//3.2============================================================================
	std::list<unsigned int> l0(100);  // unsigned int: int without - or +, start from 0
	//std::generate( std::begin(l0), std::end(l0), randNum );
	for (std::list<unsigned int>::iterator i = l0.begin(); i != l0.end(); ++i)
	{
		*i = randNum();
	}
	//std::copy( std::begin(l0), std::end(l0), std::ostream_iterator <int> (std::cout, "\n") );
	
	std::vector<unsigned int> v0(100);
	std::copy( std::begin(l0), std::end(l0), std::begin(v0) );
	//std::copy( std::begin(v0), std::end(v0), std::ostream_iterator <int> (std::cout, "\n") );


	//3.3============================================================================
	std::set<int> s;
	for (std::list<unsigned int>::iterator i = l0.begin(); i != l0.end(); ++i)
	 {
	 	s.insert(*i);
	 } 
	std::copy( std::begin(s), std::end(s), std::ostream_iterator <int> (std::cout, "\n") );
	std::cout << "Anzahl unterschiedlicher Zahlen = " << s.size() << std::endl;
	// the numbers not in the list
	for (int i = 0; i <= 100; ++i)
	{
		if (s.count(i)==0)
		{
			std::cout << i << std::endl;
		}
	}


	//3.4============================================================================
	std::map<int, int> map;
	for (std::list<unsigned int>::iterator i = l0.begin(); i != l0.end(); ++i)
	{
		if (map.count(*i)==0)
		{
			map.insert( std::pair<int,int> (*i, 1) );
		}
		else
		{
			map[*i] += 1;
		}
	}
	for (auto const& chart : map)
	{
		std::cout << chart.first << ", " << chart.second << std::endl;
	}


	return 0;
}