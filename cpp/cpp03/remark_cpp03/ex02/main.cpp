/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 20:48:40 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 20:48:41 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int	main(void)
{
	FragTrap	a("a");
	ScavTrap	b("b");

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;
	b.guardGuate();
	std::cout << std::endl;
	a.highFivesGuys();
	std::cout << std::endl;
	return (0);
}
