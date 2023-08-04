/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 07:08:55 by jlim              #+#    #+#             */
/*   Updated: 2022/02/17 07:08:56 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap() : ClapTrap(), _guard_mode(false)
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
	std::cout << GREEN;
	std::cout << "ScavTrap default constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ScavTrap::ScavTrap(const ScavTrap &src) : ClapTrap(src), _guard_mode(src._guard_mode)
{
	std::cout << GREEN;
	std::cout << "ScavTrap copy constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name), _guard_mode(false)
{
	_hit = 100;
	_energy = 50;
	_damage = 20;
	std::cout << GREEN;
	std::cout << "ScavTrap string constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ScavTrap::~ScavTrap()
{
	std::cout << RED;
	std::cout << "ScavTrap destructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ScavTrap	&ScavTrap::operator=(ScavTrap const &src)
{
	ClapTrap::operator=(src);
	_guard_mode = src._guard_mode;
	std::cout << CYAN;
	std::cout << "ScapTrap operator = (" << _name << ") called" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	ScavTrap::attack(std::string const &target)
{
	std::cout << YELLOW;
	std::cout << "ScavTrap " << _name << " attacks " << target << " causing " << _damage << " points of damage!" << std::endl;
	std::cout << RESET;
}

void	ScavTrap::guardGuate(void)
{
	std::cout << YELLOW;
	if (_energy)
	{
		std::cout << "ScavTrap " << _name << " switch to guard mode" << std::endl;
		_guard_mode = true;
	}
	else
		std::cout << "ScavTrap " << _name << " could not switch to guard mode because he is dead" << std::endl;
	std::cout << RESET;
}