/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   re_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:32:53 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 12:36:55 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_list **a_list, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*a_list) || !(*a_list)->next)
		return ;
	tmp = *a_list;
	cp = *a_list;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *a_list;
	*a_list = tmp;
	if (p != 1)
		write(1, "rra\n", 4);
}

void	rrb(t_list **b_list, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*b_list) || !(*b_list)->next)
		return ;
	tmp = *b_list;
	cp = *b_list;
	while (tmp->next)
	{
		if (tmp->next->next)
			cp = cp->next;
		tmp = tmp->next;
	}
	cp->next = NULL;
	tmp->next = *b_list;
	*b_list = tmp;
	if (p != 1)
		write(1, "rrb\n", 4);
}

void	rrr(t_list **a_list, t_list **b_list, int p)
{
	rra(a_list, 1);
	rrb(b_list, 1);
	if (p != 1)
		write(1, "rrr\n", 4);
}
