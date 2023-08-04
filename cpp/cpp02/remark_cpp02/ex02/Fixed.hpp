/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:42:36 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 13:42:38 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
private:
	int					_value;
	const static int	_bits;
public:
	Fixed(void);
	~Fixed(void);
	Fixed(const int Fixed);
	Fixed(const float Fixed);
	Fixed(const Fixed &src);

	Fixed	&operator=(const Fixed &src);
	bool	operator>(Fixed const &src) const;
	bool	operator<(Fixed const &src) const;
	bool	operator>=(Fixed const &src) const;
	bool	operator<=(Fixed const &src) const;
	bool	operator==(Fixed const &src) const;
	bool	operator!=(Fixed const &src) const;
	Fixed	operator+(Fixed const &src) const;
	Fixed	operator-(Fixed const &src) const;
	Fixed	operator*(Fixed const &src) const;
	Fixed	operator/(Fixed const &src) const;
	Fixed	&operator++(void);
	Fixed	operator++(int);
	Fixed	&operator--(void);
	Fixed	operator--(int);

	int		getRawBits(void) const;
	void	setRawBits(int const raw);

	int		toInt(void) const;
	float	toFloat(void) const;

	static Fixed		&min(Fixed &f1, Fixed &f2);
	static Fixed const	&min(Fixed const &f1, Fixed const &f2);
	static Fixed		&max(Fixed &f1, Fixed &f2);
	static Fixed const	&max(Fixed const &f1, Fixed const &f2);

};

std::ostream	&operator<<(std::ostream &s, const Fixed &Fixed);

#endif