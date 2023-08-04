/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:26:11 by jlim              #+#    #+#             */
/*   Updated: 2022/02/17 08:26:13 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap() : _name(ClapTrap::_name)
{
	ClapTrap::_name += "_clap_name";
	_energy = 50;
	std::cout << GREEN;
	std::cout << "DiamondTrap default constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

DiamondTrap::DiamondTrap(const DiamondTrap &src) : ClapTrap(src), ScavTrap(src), FragTrap(src), _name(src._name)
{
	std::cout << GREEN;
	std::cout << "DiamondTrap copy constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name"), ScavTrap(name), FragTrap(name), _name(name)
{
	_energy = 50;
	std::cout << GREEN;
	std::cout << "DiamondTrap string constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << RED;
	std::cout << "DiamondTrap destructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

DiamondTrap	&DiamondTrap::operator=(DiamondTrap const &src)
{
	ScavTrap::operator=(src);
	_name = src._name;
	std::cout << CYAN;
	std::cout << "DiamondTrap operator = (" << _name << ") called" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	DiamondTrap::whoAmI(void) const
{
	std::cout << YELLOW;
	std::cout << "This DiamondTrap name is " << _name << " and This ClapTrap name is " << ClapTrap::_name << std::endl;
	std::cout << RESET;
}
