/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 13:26:42 by jlim              #+#    #+#             */
/*   Updated: 2022/02/28 13:26:43 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

/*
int	main(void)
{
	std::string	s[5] = {"s1", "s2", "s3", "s4", "s5"};
	char		c[5] = {'a', 'b', 'c', 'd', 'e'};
	int			i[5] = {1, 2, 3, 4, 5};
	float		f[5] = {1.f, 2.f, 3.f, 4.f, 5.f};
	double		d[5] = {1.0, 2.0, 3.0, 4.0, 5.0};

	std::cout << "s : ";
	iter<std::string>(s, sizeof(s) / sizeof(*s), print<std::string>);
	std::cout << "c : ";
	iter<char>(c, sizeof(c) / sizeof(*c), print);
	std::cout << "i : ";
	iter(i, sizeof(i) / sizeof(*i), print<int>);
	std::cout << "f : ";
	iter(f, sizeof(f) / sizeof(*f), print);
	std::cout << "d : ";
	iter(d, sizeof(d) / sizeof(*d), print);
	
	return (0);
}*/

class Awesome
{
public:
Awesome( void ) : _n( 42 ) { return; }
int get( void ) const { return this->_n; }
private:
int _n;
};
std::ostream & operator<<( std::ostream & o, Awesome const & rhs ) { o << rhs.get(); return o; }
template< typename T >
void print( T const & x ) { std::cout << x << std::endl; return; }
int main() {
int tab[] = { 0, 1, 2, 3, 4 }; // <--- I never understood why you can't write int[] tab. Wouldn't that make more sense?
Awesome tab2[5];
iter( tab, 5, print );
iter( tab2, 5, print );
return 0;
}
