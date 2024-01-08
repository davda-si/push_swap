/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 16:22:17 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/03 14:48:47 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_pswp **stack)
{
	*stack = (*stack)->next;
	(*stack)->prev->prev = (*stack);
	(*stack)->prev->next = (*stack)->next;
	if ((*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_pswp **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_pswp **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_pswp **a, t_pswp **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}
