/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:14:19 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 11:21:47 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sort(t_list *a_list)
{
	while (a_list->next)
	{
		if (a_list->content > a_list->next->content)
			return (0);
		a_list = a_list ->next;
	}
	return (1);
}

int	get_size(t_list *list)
{
	int	i;

	i = 0;
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}

int	get_max(t_list *list, int diff)
{
	int	max;

	max = -2147483648;
	while (list)
	{
		if (list->content > max && list->content != diff)
			max = list->content;
		list = list->next;
	}
	return (max);
}

int	get_min(t_list *list)
{
	int	min;

	min = 2147483647;
	while (list)
	{
		if (list->content < min)
			min = list->content;
		list = list->next;
	}
	return (min);
}

int	get_order(int n, t_list *list)
{
	int	order;

	order = 0;
	while (list->content != n)
	{
		list = list->next;
		order++;
	}
	return (order);
}
