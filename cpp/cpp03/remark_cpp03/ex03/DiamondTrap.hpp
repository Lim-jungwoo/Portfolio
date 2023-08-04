/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:26:20 by jlim              #+#    #+#             */
/*   Updated: 2022/02/17 08:26:20 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMONDTRAP_HPP
# define DIAMONDTRAP_HPP

# include <iostream>
# include <string>
# include "FragTrap.hpp"
# include "ScavTrap.hpp"

class DiamondTrap : public ScavTrap, public FragTrap
{
private:
	std::string	_name;
public:
	DiamondTrap();
	~DiamondTrap();
	DiamondTrap(DiamondTrap const &src);
	DiamondTrap(std::string name);

	DiamondTrap	&operator=(DiamondTrap const &src);

	void	whoAmI(void) const;
	using	ScavTrap::attack;
	using	ScavTrap::_energy;
};

#endif