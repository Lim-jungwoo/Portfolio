/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/17 08:12:45 by jlim              #+#    #+#             */
/*   Updated: 2022/02/17 08:12:46 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include <iostream>
# include <string>
# include "ClapTrap.hpp"

class FragTrap : public ClapTrap
{

public:
	FragTrap();
	~FragTrap();
	FragTrap(FragTrap const &src);
	FragTrap(std::string name);

	FragTrap	&operator=(FragTrap const &src);

	void	highFivesGuys(void);
};

#endif