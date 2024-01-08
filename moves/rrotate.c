/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:46:13 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/13 16:38:33 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rrotate(t_pswp **stack)
{
	t_pswp	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ps_lstlast(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	*stack = last;
	last->next->prev = last;
}

void	rra(t_pswp **a)
{
	rrotate(a);
	ft_printf("rra\n");
}

void	rrb(t_pswp **b)
{
	rrotate(b);
	ft_printf("rrb\n");
}

void	rrr(t_pswp **a, t_pswp **b)
{
	rrotate(a);
	rrotate(b);
	ft_printf("rrr\n");
}
