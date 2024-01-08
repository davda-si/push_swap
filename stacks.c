/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 16:20:44 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/13 16:42:23 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	alr_sort(t_pswp *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nb > stack->next->nb)
			return (0);
		stack = stack->next;
	}
	return (1);
}

t_pswp	*find_big(t_pswp *stack)
{
	long	max;
	t_pswp	*m_node;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nb > max)
		{
			max = stack->nb;
			m_node = stack;
		}
		stack = stack->next;
	}
	return (m_node);
}

t_pswp	*find_small(t_pswp *stack)
{
	long	min;
	t_pswp	*m_node;

	if (!stack)
		return (NULL);
	min = LONG_MAX;
	while (stack)
	{
		if (stack->nb < min)
		{
			min = stack->nb;
			m_node = stack;
		}
		stack = stack->next;
	}
	return (m_node);
}

void	arrange(t_pswp **stack, t_pswp *top, char n)
{
	while (*stack != top)
	{
		if (n == 'a')
		{
			if (top->up_mid)
				ra(stack);
			else
				rra(stack);
		}
		else if (n == 'b')
		{
			if (top->up_mid)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

int	ps_lstsize(t_pswp *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst->next)
	{
		i++;
		lst = lst->next;
	}
	return (i + 1);
}
