/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 14:11:02 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 14:11:03 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
}

Point::Point(const Point &src) : _x(src._x), _y(src._y)
{
}

Point::Point(Fixed const x, Fixed const y) : _x(x), _y(y)
{
}

Point::~Point()
{
}

Point	&Point::operator=(Point const &src)
{//고쳐야될 듯
	(void)src;
	return (*this);
}

Fixed	Point::get_x(void) const
{
	return (this->_x);
}

Fixed	Point::get_y(void) const
{
	return (this->_y);
}