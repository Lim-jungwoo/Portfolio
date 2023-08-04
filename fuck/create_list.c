/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:06:23 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 14:01:22 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_arg(char *s)
{
	long long	num;

	num = ft_atoi1(s);
	if (num == 3000000000 || num < -2147483648 || num > 2147483647)
		return (0);
	return (1);
}

int	check_dup(t_list *list)
{
	int		n;
	t_list	*tmp;

	n = list->content;
	tmp = list;
	while (list->next)
	{
		list = list->next;
		if (list->content == n)
			return (0);
	}
	if (tmp->next)
		if (!(check_dup(tmp->next)))
			return (0);
	return (1);
}

t_list	*fill_list(t_list *list, int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		add_list(&list, ft_atoi2(&av[i][j]));
		i++;
	}
	return (list);
}

t_list	*create_list(int ac, char **av)
{
	t_list	*list;
	int		i;

	i = 1;
	list = NULL;
	while (i < ac)
	{
		if (!(check_arg(av[i])) || !av[1][0])
			return (0);
		i++;
	}
	list = fill_list(list, ac, av);
	if (!(check_dup(list)))
	{
		free_list(list);
		return (NULL);
	}
	return (list);
}
