#include "container/stack.hpp"
#include "container/map.hpp"
#include <vector>
#include <map>
#include <stack>
#include <iostream>

#include <random>

int	main(void)
{
	std::random_device randDev;
	std::mt19937 generator(randDev());
	std::uniform_int_distribution<int> distr(0, 1e8);

	ft::vector<int>		vec1;
	ft::vector<int>::iterator	vecit1;
	size_t	num = 1e6;
	for (size_t i = 0; i <num; i++)
		vec1.push_back(i);
	vec1.clear();

	ft::map<int, int>	map1;
	ft::map<int, int>::iterator	mapit1;
	for (size_t i = 0; i < num; i++)
		map1.insert(ft::pair<int, int>(i, i));
	for (size_t i = 0; i < num; i++)
	{
		int n = distr(generator);
		map1.erase(n);
	}
	map1.clear();
	while (1)
	{}
}