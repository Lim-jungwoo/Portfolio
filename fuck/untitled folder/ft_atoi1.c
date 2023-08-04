/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:06:51 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 14:00:51 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_sign(const char *str, int *min)
{
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str == '-')
	{
		str++;
		(*min)++;
	}
	else if (*str == '+')
		str++;
	return ;
}

long long	ft_atoi1(const char *str)
{
	long long	number;
	int			min;

	number = 0;
	min = 0;
	check_sign(str, &min);
	if (*str < '0' || *str > '9')
		return (3000000000);
	while (*str >= '0' && *str <= '9')
	{
		number *= 10;
		number += (*str - '0');
		str++;
	}
	if (*str && (*str < '0' || *str > '9'))
		return (3000000000);
	if (min == 1)
		number *= -1;
	return (number);
}
