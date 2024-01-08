/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 20:03:09 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/02 20:17:24 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_pswp **stack)
{
	t_pswp	*last;

	if (!*stack || !(*stack)->next)
		return ;
	last = ps_lstlast(*stack);
	last->next = *stack;
	*stack = (*stack)->next;
	(*stack)->prev = NULL;
	last->next->prev = last;
	last->next->next = NULL;
}

void	ra(t_pswp **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_pswp **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_pswp **a, t_pswp **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
