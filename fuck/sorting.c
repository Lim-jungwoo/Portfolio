/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 11:22:18 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 14:15:14 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.c"

void	push_max(t_list **a_list, t_list **b_list, int max, t_info *info)
{
	int	condition;

	condition = 0;
	if ((*b_list)->content < max)
	{
		while ((*b_list)->content != max)
		{
			if ((*b_list)->next->content == max)
			{
				sb(*b_list, 0);
				pa(a_list, b_list, 0);
				condition = 1;
				break ;
			}
			if (info->flags == 1)
				rb(b_list, 0);
			else
				rrb(b_list, 0);
		}
	}
	if (!condition)
		pa(a_list, b_list, 0);
}

void	push_btoa2(t_list **b_list, t_data *data)
{
	data->flags_b1 = 0;
	data->flags_b2 = 0;
	data->max_b1 = get_max(*b_list, -2147483648);
	data->max_b2 = get_max(*b_list, data->max_b1);
	data->order_b1 = get_order(data->max_b1, *b_list);
	data->order_b2 = get_order(data->max_b2, *b_list);
}

void	push_btoa(t_list **a_list, t_list **b_list, t_info *info,
		t_data *data)
{
	while (info->size_b)
	{
		push_btoa2(b_list, data);
		if (data->order_b1 < info->size_b / 2)
			data->flags_b1 = 1;
		if (data->max_b2 != -2147483648 && data->order_b2 < info->size_b / 2)
			data->flags_b2 = 1;
		info->flags = data->flags_b1;
		if (data->max_b2 != -2147483648 && data->flags_b1 == data->flags_b2
			&& ((data->order_b1 > data->order_b2 && data->flags_b1)
				|| (data->order_b1 < data->order_b2 && !data->flags_b1)))
		{
			push_max(a_list, b_list, data->max_b2, info);
			push_max(a_list, b_list, data->max_b1, info);
			sa(*a_list, 0);
			info->size_b--;
		}
		else
			push_max(a_list, b_list, data->max_b1, info);
		info->size_b--;
	}
}

void	quick_sort(int a_size, t_list **a_list, t_list **b_list,
		t_info **info)
{
	while (a_size && (*info)->size_a > 2)
	{
		if ((*a_list)->content <= (*info)->pivot)
		{
			pb(a_list, b_list, 0);
			if ((*b_list)->content < get_median(*b_list, (*info)->size_b)
				&& (*info)->size_b > 1)
			{
				if ((*a_list)->content > (*info)->pivot)
					rr(a_list, b_list, 0);
				else
					rb(b_list, 0);
			}
			(*info)->size_b++;
			(*info)->size_a--;
		}
		else
			ra(a_list, 0);
		a_size--;
	}
}

int	sorting(t_list **a_list, t_info *info)
{
	int		a_size;
	t_data	*data;
	t_list	*b_list;

	b_list = 0;
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	if (is_sort(*a_list))
		return (1);
	info->size_a = get_size(*a_list);
	info->size_b = 0;
	while (info->size_a > 2)
	{
		info->pivot = get_median(*a_list, info->size_a);
		a_size = info->size_a;
		quick_sort(a_size, a_list, &b_list, &info);
	}
	pb(a_list, &b_list, 0);
	pb(a_list, &b_list, 0);
	info->size_b += 2;
	push_btoa(a_list, &b_list, info, data);
	free(data);
	return (1);
}
