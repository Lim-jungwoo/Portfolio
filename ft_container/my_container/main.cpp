#include "vector.hpp"
#include <iostream>
#include <vector>
#include <map>
#include "map3.hpp"

int	main()
{
	ft::map<int, int>	map1;
	ft::map<int, int>	map2;
	ft::map<int, int>::iterator	it1;
	ft::map<int, int>::iterator	it2;
	ft::map<int, int>::iterator	it3;
	ft::map<int, int>::iterator	it4;
	map1.insert(ft::pair<int, int>(13, 2));
	map1.insert(ft::pair<int, int>(4, 87));
	map1.insert(ft::pair<int, int>(5, 2));
	map1.insert(ft::pair<int, int>(6, 2));
	map1.insert(ft::pair<int, int>(24, 2));
	map2.insert(ft::pair<int, int>(542, 312));
	map2.insert(ft::pair<int, int>(645, 312));
	map2.insert(ft::pair<int, int>(675, 312));
	map2.insert(ft::pair<int, int>(653489, 312));
	map2 = map1;
	map2.erase(24);
	// map1.insert(ft::pair<int, int>(1, 1));
	// map1.clear();
	// map2.clear();
	if (map1 > map2)
		std::cout << "map1 > map2\n";
	else
		std::cout << "map1 <= map2\n";
	// map1.swap(map2);
	// it1 = map1.begin();
	// it2 = map1.end();
	// it3 = map2.begin();
	// it4 = map2.end();
	// while (it1 != it2)
	// {
	// 	std::cout << "map1 : " << it1->first << std::endl;
	// 	it1++;
	// }
	// while (it3 != it4)
	// {
	// 	std::cout << "map2 : " << it3->first << std::endl;
	// 	it3++;
	// }
	

	// std::map<int, int>	map1;
	// std::map<int, int>	map2;
	// map1.insert(std::pair<int, int>(13, 2));
	// map1.insert(std::pair<int, int>(4, 87));
	// map1.insert(std::pair<int, int>(5, 2));
	// map1.insert(std::pair<int, int>(6, 2));
	// map1.insert(std::pair<int, int>(532, 2));
	// map2.insert(std::pair<int, int>(7543, 2));
	// map2.insert(std::pair<int, int>(243, 2));
	// map2.insert(std::pair<int, int>(24, 2));
	// map2 = map1;
	// map2.erase(532);
	// // map1.begin()->second = -10;
	// // map1.clear();
	// // map2.clear();
	// if (map1 > map2)
	// 	std::cout << "map1 > map2\n";
	// else
	// 	std::cout << "map1 <= map2\n";
}
