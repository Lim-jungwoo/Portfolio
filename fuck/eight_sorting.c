/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eight_sorting.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:14:50 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 12:26:39 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_atob(int size, t_list **a_list, t_list **b_list)
{
	int	j;
	int	i;

	i = 0;
	while (i++ < 2)
	{
		j = 0;
		if (get_order(get_min(*a_list), *a_list) < size / 2)
			j = 1;
		while ((*a_list)->content != get_min(*a_list))
		{
			if (j)
				ra(a_list, 0);
			else
				rra(a_list, 0);
		}
		pb(a_list, b_list, 0);
	}
}

void	eight_sorting(t_list **a_list)
{
	int		size;
	t_list	*b_list;

	b_list = 0;
	size = get_size(*a_list);
	if (is_sort(*a_list))
		return ;
	if (size > 3)
		push_atob(size, a_list, &b_list);
	while (!is_sort(*a_list))
	{
		if ((*a_list)->content >= get_max(*a_list, -2147483648))
			ra(a_list, 0);
		else if ((*a_list)->content > (*a_list)->next->content)
			sa(*a_list, 0);
		else
			ra(a_list, 0);
	}
	if (size > 3)
	{
		pa(a_list, &b_list, 0);
		pa(a_list, &b_list, 0);
	}
}
