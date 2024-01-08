/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 19:39:57 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/13 16:48:31 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pswp	*ps_lstlast(t_pswp *lst)
{
	t_pswp	*ls;

	ls = lst;
	if (ls != NULL)
	{
		while (ls->next != NULL)
			ls = ls->next;
	}
	return (ls);
}

void	target_b(t_pswp *a, t_pswp *b)
{
	t_pswp	*cur_a;
	t_pswp	*target;
	long	best;

	while (b)
	{
		best = LONG_MAX;
		cur_a = a;
		while (cur_a)
		{
			if ((cur_a->nb > b->nb) && (cur_a->nb < best))
			{
				best = cur_a->nb;
				target = cur_a;
			}
			cur_a = cur_a->next;
		}
		if (best == LONG_MAX)
			b->tgrt = find_small(a);
		else
			b->tgrt = target;
		b = b->next;
	}
}

void	move_ba(t_pswp **a, t_pswp **b)
{
	arrange(a, (*b)->tgrt, 'a');
	pa(a, b);
}

void	rotation(t_pswp **a, t_pswp **b, t_pswp *ch_node, int flag)
{
	if (flag == 0)
	{
		while (*b != ch_node->tgrt && *a != ch_node)
			rr(a, b);
		ft_index(*a);
		ft_index(*b);
	}
	else if (flag == 1)
	{
		while (*b != ch_node->tgrt && *a != ch_node)
			rrr(a, b);
		ft_index(*a);
		ft_index(*b);
	}
}
