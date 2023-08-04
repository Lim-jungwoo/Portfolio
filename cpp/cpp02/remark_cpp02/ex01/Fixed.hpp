/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 13:25:42 by jlim              #+#    #+#             */
/*   Updated: 2022/02/16 13:25:43 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath> //roundf함수

class Fixed
{
private:
	int					_value;
	const static int	_bits;
public:
	Fixed(void); //기본 생성자
	~Fixed(void); //소멸자
	Fixed(const int Fixed); //int를 인자로 받는 생성자
	Fixed(const float Fixed); //float를 인자로 받는 생성자
	Fixed(const Fixed &src); //복사 생성자

	Fixed &operator=(Fixed const &src); //대입 연산자

	int		getRawBits(void) const; //_value값을 리턴
	void	setRawBits(int const raw); //raw값으로 _value값 설정

	int		toInt(void) const; 
	float	toFloat(void) const;
};

std::ostream &operator<<(std::ostream &s, const Fixed &Fixed);

#endif
