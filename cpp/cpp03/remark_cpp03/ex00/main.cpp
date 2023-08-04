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

#include "ClapTrap.hpp"

int	main(void)
{
	ClapTrap	a("a");
	ClapTrap	b("b");
	ClapTrap	c("c");

	std::cout << std::endl;
	a.attack("b");
	b.takeDamage(a.getDamage());
	std::cout << std::endl;
	b.attack("a");
	a.takeDamage(b.getDamage());
	std::cout << std::endl;
	c.attack("b");
	b.takeDamage(c.getDamage());
	std::cout << std::endl;
	a.beRepaired(25);
	std::cout << std::endl;
	return (0);
}
