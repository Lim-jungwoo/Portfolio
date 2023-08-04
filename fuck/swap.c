/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 12:37:04 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 12:39:29 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_list *a_list, int p)
{
	if (!a_list)
		return ;
	if (a_list->next)
	{
		ft_swap(&a_list->content, &a_list->next->content);
		if (p != 1)
			write(1, "sa\n", 3);
	}
}

void	sb(t_list *b_list, int p)
{
	if (!b_list)
		return ;
	if (b_list->next)
	{
		ft_swap(&b_list->content, &b_list->next->content);
		if (p != 1)
			write(1, "sb\n", 3);
	}
}

void	ss(t_list *a_list, t_list *b_list, int p)
{
	sa(a_list, 1);
	sb(b_list, 1);
	if (p != 1)
		write(1, "ss\n", 3);
}
