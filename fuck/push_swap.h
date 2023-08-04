/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlim <jlim@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 09:50:51 by jlim              #+#    #+#             */
/*   Updated: 2021/09/29 13:47:23 by jlim             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct s_list
{
	int				content;
	struct s_list	*next;
}				t_list;

typedef struct s_info
{
	int	pivot;
	int	size_b;
	int	size_a;
	int	flags;
}				t_info;

typedef struct s_data
{
	int	max_b1;
	int	max_b2;
	int	flags_b1;
	int	flags_b2;
	int	order_b1;
	int	order_b2;
}				t_data;

int		sorting(t_list **list_a, t_info *info);
int		free_all(t_list *list, t_info *info);
void	eight_sorting(t_list **list_a);
int		get_min(t_list *list);
int		get_max(t_list *list, int diff);
int		get_order(int n, t_list *list);
int		get_size(t_list *list);
void	free_list(t_list *list);
void	sa(t_list *a_list, int p);
void	sb(t_list *b_list, int p);
void	ss(t_list *a_list, t_list *b_list, int p);
void	pa(t_list **a_list, t_list **b_list, int p);
void	pb(t_list **a_list, t_list **b_list, int p);
void	ra(t_list **a_list, int p);
void	rb(t_list **b_list, int p);
void	rr(t_list **a_list, t_list **b_list, int p);
void	rra(t_list **a_list, int p);
void	rrb(t_list **b_list, int p);
void	rrr(t_list **a_list, t_list **b_List, int p);
int		is_sort(t_list *a_list);
int		get_median(t_list *b_list, int size);
void	add_list(t_list **list, int n);
t_list	*create_list(int ac, char **av);

#endif
