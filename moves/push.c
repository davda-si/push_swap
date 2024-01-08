/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 15:55:08 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/07 21:03:08 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_pswp **src, t_pswp **dst)
{
	t_pswp	*n_push;

	if (!(*src))
		return ;
	n_push = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	n_push->prev = NULL;
	if (!*dst)
	{
		*dst = n_push;
		n_push->next = NULL;
	}
	else
	{
		n_push->next = *dst;
		*dst = n_push;
		n_push->next->prev = n_push;
	}
}

void	pa(t_pswp **a, t_pswp **b)
{
	push(b, a);
	ft_printf("pa\n");
}

void	pb(t_pswp **a, t_pswp **b)
{
	push(a, b);
	ft_printf("pb\n");
}
