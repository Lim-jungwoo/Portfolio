/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:47:50 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 20:47:51 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap() : _name("default"), _hit(10), _energy(10), _damage(0)
{
	std::cout << GREEN;
	std::cout << "ClapTrap default constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(const ClapTrap &src) : _name(src._name), _hit(src._hit), _energy(src._energy), _damage(src._damage)
{
	std::cout << GREEN;
	std::cout << "ClapTrap copy constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit(10), _energy(10), _damage(0)
{
	std::cout << GREEN;
	std::cout << "ClapTrap string constructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ClapTrap::~ClapTrap()
{
	std::cout << RED;
	std::cout << "ClapTrap destructor (" << _name << ") called" << std::endl;
	std::cout << RESET;
}

ClapTrap	&ClapTrap::operator=(ClapTrap const &src)
{
	_name = src._name;
	_hit = src._hit;
	_energy = src._energy;
	_damage = src._damage;
	std::cout << CYAN;
	std::cout << "ClapTrap operator = (" << _name << ") called" << std::endl;
	std::cout << RESET;
	return (*this);
}

void	ClapTrap::attack(std::string const &target)
{
	std::cout << YELLOW;
	std::cout << "ClapTrap " << _name << " attacks " << target << ", causing " << _damage << " points of damage!" << std::endl;
	std::cout << RESET;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	std::cout << YELLOW;
	std::cout << "ClapTrap " << _name << " has taken " << amount << " points of damage" << std::endl;
	if (amount >= _energy)
	{
		_energy = 0;
		std::cout << "ClapTrap " << _name << " died" << std::endl;
	}
	else
	{
		_energy -= amount;
		std::cout << "ClapTrap " << _name << "'s energy points is now " << _energy << std::endl;
	}
	std::cout << RESET;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	std::cout << YELLOW;
	if (!_energy)
	{
		_energy = amount;
		std::cout << "ClapTrap " << _name << " has been repaired and is back to life with " << amount << " energy points" << std::endl;
	}
	else
	{
		_energy += amount;
		std::cout << "ClapTrap " << _name << " has been repaired of " << amount << " energy points. It has now " << _energy << " energy points" << std::endl;
	}
	std::cout << RESET;
}

unsigned int	ClapTrap::getDamage(void) const
{
	return (this->_damage);
}