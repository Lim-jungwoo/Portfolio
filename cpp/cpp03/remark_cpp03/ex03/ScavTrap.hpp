/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 07:09:03 by jlim              #+#    #+#             */
/*   Updated: 2022/02/17 07:09:04 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class ScavTrap : virtual public ClapTrap
{
public:
	ScavTrap();
	~ScavTrap();
	ScavTrap(ScavTrap const &src);
	ScavTrap(std::string name);

	ScavTrap	&operator=(ScavTrap const &src);

	void	attack(std::string const &target);
	void	guardGuate(void);

protected:
	bool	_guard_mode;
};

#endif
