/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/29 18:58:19 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 09:18:47 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	put_result(long long number, long long digit, int fd)
{
	while (digit)
	{
		ft_putchar_fd((char)(number / digit + '0'), fd);
		number -= (number / digit) * digit;
		digit /= 10;
	}
	return ;
}

void	ft_putnbr_fd(int n, int fd)
{
	long long	number;
	long long	digit;

	number = n;
	digit = 1;
	if (n < 0)
	{
		number *= -1;
		write(fd, "-", 1);
	}
	while (1)
	{
		if (number < (digit * 10))
			break ;
		digit *= 10;
	}
	if (number == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	put_result(number, digit, fd);
	return ;
}
