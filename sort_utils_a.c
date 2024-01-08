/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:52:24 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/13 16:43:34 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pswp	*get_cheap(t_pswp *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheap)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

void	target_a(t_pswp *a, t_pswp *b)
{
	t_pswp	*cur_b;
	t_pswp	*target;
	long	best;

	target = NULL;
	while (a)
	{
		best = LONG_MIN;
		cur_b = b;
		while (cur_b)
		{
			if ((cur_b->nb < a->nb) && (cur_b->nb > best))
			{
				best = cur_b->nb;
				target = cur_b;
			}
			cur_b = cur_b->next;
		}
		if (best == LONG_MIN)
			a->tgrt = find_small(b);
		else
			a->tgrt = target;
		a = a->next;
	}
}

void	check_cost_a(t_pswp *a, t_pswp *b)
{
	int	i;
	int	j;

	i = ps_lstsize(a);
	j = ps_lstsize(b);
	while (a)
	{
		a->cost = a->dex;
		if (!(a->up_mid))
			a->cost = i - (a->dex);
		if (a->tgrt->up_mid)
			a->cost += (a->tgrt->dex);
		else
			a->cost += j - (a->tgrt->dex);
		a = a->next;
	}
}

void	cheap_n(t_pswp *stack)
{
	long	val;
	t_pswp	*ch_node;

	if (!stack)
		return ;
	val = LONG_MAX;
	ch_node = NULL;
	while (stack)
	{
		if (stack->cost < val)
		{
			val = stack->cost;
			ch_node = stack;
		}
		stack = stack->next;
	}
	if (ch_node)
		ch_node->cheap = 1;
	else
		ch_node->cheap = 0;
}

void	move_ab(t_pswp **a, t_pswp **b)
{
	t_pswp	*ch_node;

	ch_node = get_cheap(*a);
	if (ch_node->up_mid && ch_node->tgrt->up_mid)
		rotation(a, b, ch_node, 0);
	else if (!(ch_node->up_mid) && !(ch_node->tgrt->up_mid))
		rotation(a, b, ch_node, 1);
	arrange(a, ch_node, 'a');
	arrange(b, ch_node->tgrt, 'b');
	pb(a, b);
}
