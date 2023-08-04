/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:12:39 by jlim              #+#    #+#             */
/*   Updated: 2022/02/17 08:12:40 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap() : ClapTrap()
{
	_hit = 100;
	_energy = 100;
	_damage = 30;
	std::cout << GREEN;
	std::cout << "FragTrap default constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

FragTrap::FragTrap(const FragTrap &src) : ClapTrap(src)
{
	std::cout << GREEN;
	std::cout << "FragTrap copy constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	_hit = 100;
	_energy = 100;
	_damage = 30;
	std::cout << GREEN;
	std::cout << "FragTrap string constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

FragTrap::~FragTrap()
{
	std::cout << RED;
	std::cout << "FragTrap destructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

FragTrap	&FragTrap::operator=(FragTrap const &src)
{
	ClapTrap::operator=(src);
	std::cout << CYAN;
	std::cout << "FragTrap operator = (" << _name << ") called" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << YELLOW;
	std::cout << "FragTrap " << _name << " positive high fives request" << std::endl;
	std::cout << RESET;
}
