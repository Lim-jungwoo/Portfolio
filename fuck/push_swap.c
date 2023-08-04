/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:47:38 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 10:05:36 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_swap(t_list **a_list, t_info *info)
{
	if (get_size(*a_list) > 8)
	{
		if (!(sorting(a_list, info)))
			return (0);
	}
	else
		eight_sorting(a_list);
	return (1);
}

int	main(int ac, char **av)
{
	t_list	*a_list;
	t_info	*info;

	if (ac < 2)
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	a_list = create_list(ac, av);
	if (!a_list)
	{
		free(info);
		return (write(2, "Error\n", 6));
	}
	push_swap(&a_list, info);
	free_list(a_list);
	free(info);
	return (0);
}
