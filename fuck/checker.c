/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:39:57 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 12:52:08 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	compare(char *line, t_list **a_list, t_list **b_list)
{
	if (!(ft_strcmp(line, "ra")))
		ra(a_list, 1);
	else if (!(ft_strcmp(line, "rb")))
		rb(b_list, 1);
	else if (!(ft_strcmp(line, "rr")))
		rr(a_list, b_list, 1);
	else if (!(ft_strcmp(line, "sa")))
		sa(*a_list, 1);
	else if (!(ft_strcmp(line, "sb")))
		sb(*b_list, 1);
	else if (!(ft_strcmp(line, "ss")))
		ss(*a_list, *b_list, 1);
	else if (!(ft_strcmp(line, "rra")))
		rra(a_list, 1);
	else if (!(ft_strcmp(line, "rrb")))
		rrb(b_list, 1);
	else if (!(ft_strcmp(line, "rrr")))
		rrr(a_list, b_list, 1);
	else if (!(ft_strcmp(line, "pa")))
		pa(a_list, b_list, 1);
	else if (!(ft_strcmp(line, "pb")))
		pb(a_list, b_list, 1);
	else
		return (0);
	return (1);
}

int	checker(t_list **a_list, t_list **b_list)
{
	int		ret;
	char	*line;

	ret = get_next_line(0, &line);
	while (ret > 0)
	{
		if (ret == -1)
		{
			free(line);
			return (0);
		}
		if (!(compare(line, a_list, b_list)))
		{
			free(line);
			return (0);
		}
		free(line);
		ret = get_next_line(0, &line);
	}
	return (1);
}

int	main(int ac, char **av)
{
	int		ret;
	t_info	*info;
	t_list	*a_list;
	t_list	*b_list;

	if (ac < 2)
		return (0);
	info = malloc(sizeof(t_info));
	if (!info)
		return (0);
	a_list = create_list(ac, av);
	if (!a_list)
		return (free_all(a_list, info));
	ret = checker(&a_list, &b_list);
	if (!ret)
		return (free_all(a_list, info));
	if (a_list && is_sort(a_list) && !b_list)
		write(1, "OK\n", 3);
	else
		write(2, "KO\n", 3);
	if (b_list)
		free_list(b_list);
	free_all(a_list, info);
	return (0);
}
