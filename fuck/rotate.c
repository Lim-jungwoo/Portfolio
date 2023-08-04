/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:27:16 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 12:32:39 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_list **a_list, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*a_list) || !((*a_list)->next))
		return ;
	tmp = *a_list;
	cp = (*a_list)->next;
	while ((*a_list)->next)
		*a_list = (*a_list)->next;
	(*a_list)->next = tmp;
	tmp->next = NULL;
	*a_list = cp;
	if (p != 1)
		write(1, "ra\n", 3);
}

void	rb(t_list **b_list, int p)
{
	t_list	*tmp;
	t_list	*cp;

	if (!(*b_list) || !((*b_list)->next))
		return ;
	tmp = *b_list;
	cp = (*b_list)->next;
	while ((*b_list)->next)
		*b_list = (*b_list)->next;
	(*b_list)->next = tmp;
	tmp->next = NULL;
	*b_list = cp;
	if (p != 1)
		write(1, "rb\n", 3);
}

void	rr(t_list **a_list, t_list **b_list, int p)
{
	ra(a_list, 1);
	rb(b_list, 1);
	if (p != 1)
		write(1, "rr\n", 3);
}
