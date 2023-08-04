/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:11:20 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 13:11:21 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed
{
private:
	int					_value;
	const static int	_bits;
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const Fixed &f); //복사생성자
	
	Fixed	&operator=(const Fixed &f); //대입연산자

	int		getRawBits(void) const;
	void	setRawBits(int const raw);
};

#endif
