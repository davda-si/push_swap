/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:38:30 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/15 13:13:09 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_index(t_pswp *stack)
{
	int	i;
	int	mid;

	i = 0;
	if (!stack)
		return ;
	mid = ps_lstsize(stack) / 2;
	while (stack)
	{
		stack->dex = i;
		if (i <= mid)
			stack->up_mid = 1;
		else
			stack->up_mid = 0;
		stack = stack->next;
		++i;
	}
}

static void	small_top(t_pswp **a)
{
	while ((*a)->nb != find_small(*a)->nb)
	{
		if (find_small(*a)->up_mid)
			ra(a);
		else
			rra(a);
	}
}

void	init_n_a(t_pswp *a, t_pswp *b)
{
	ft_index(a);
	ft_index(b);
	target_a(a, b);
	check_cost_a(a, b);
	cheap_n(a);
}

void	init_n_b(t_pswp *a, t_pswp *b)
{
	ft_index(a);
	ft_index(b);
	target_b(a, b);
}

void	sort_it(t_pswp **a, t_pswp **b)
{
	int	l_a;

	l_a = ps_lstsize(*a);
	if (l_a-- > 3 && !alr_sort(*a))
		pb(a, b);
	if (l_a-- > 3 && !alr_sort(*a))
		pb(a, b);
	while (l_a-- > 3 && !alr_sort(*a))
	{
		init_n_a(*a, *b);
		move_ab(a, b);
	}
	small_sort(a);
	while (*b)
	{
		init_n_b(*a, *b);
		move_ba(a, b);
	}
	ft_index(*a);
	small_top(a);
}
