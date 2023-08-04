/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:10:58 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 14:10:59 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	Fixed const	_x;
	Fixed const	_y;

	Point	&operator=(Point const &src); //public으로 옮겨야 될  듯

public:
	Point(void);
	~Point(void);
	Point(Point const &src);
	Point(Fixed const x, Fixed const y);

	Fixed	get_x(void) const;
	Fixed	get_y(void) const;
};

#endif
