/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 13:47:44 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 13:50:31 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_list **a_list, t_list **b_list, int p)
{
	t_list	*tmp;

	if (!(*b_list))
		return ;
	tmp = *b_list;
	*b_list = (*b_list)->next;
	tmp->next = *a_list;
	*a_list = tmp;
	if (p != 1)
		write(1, "pa\n", 3);
}

void	pb(t_list **a_list, t_list **b_list, int p)
{
	t_list	*tmp;

	if (!(*a_list))
		return ;
	tmp = *a_list;
	*a_list = (*a_list)->next;
	tmp->next = *b_list;
	*b_list = tmp;
	if (p != 1)
		write(1, "pb\n", 3);
}
