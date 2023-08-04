#include <map>
#include <utility>
#include <sstream>
#include <iostream>



int	main(void)
{
	std::pair<int, int>	std_p1;
	pair<int, int>	ft_p1;
	std_p1.first = 10;
	std_p1.second = 20;
	ft_p1.first = 10;
	ft_p1.second = 20;
	std::cout << "first : " << std_p1.first << std::endl;
	std::cout << "second : " << std_p1.second << std::endl;
	std::cout << "ft.first : " << ft_p1.first << std::endl;
	std::cout << "ft.second : " << ft_p1.second << std::endl;
}