/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initstack_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:59:31 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/17 18:52:33 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static long	ft_atol(const char *s)
{
	long	res;
	int		i;
	int		sign;

	res = 0;
	i = 0;
	sign = 1;
	while (s[i] == ' ' || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '-' || s[i] == '+')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(s[i]))
		res = res * 10 + (s[i++] - '0');
	return (res * sign);
}

static void	add_node(t_pswp **a, int n)
{
	t_pswp	*node;
	t_pswp	*lst_n;

	if (!a)
		return ;
	node = malloc(sizeof(t_pswp));
	if (!node)
		return ;
	node->next = NULL;
	node->cheap = 0;
	node->nb = n;
	if (!(*a))
	{
		*a = node;
		node->prev = NULL;
	}
	else
	{
		lst_n = ps_lstlast(*a);
		lst_n->next = node;
		node->prev = lst_n;
	}
}

void	initstack_a(t_pswp **a, char **argv)
{
	long	n;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (invalid(argv[i]))
		{
			free_args(argv);
			free_all(a);
		}
		n = ft_atol(argv[i]);
		if (n > INT_MAX || n < INT_MIN)
		{
			free_args(argv);
			free_all(a);
		}
		if (dupl(*a, (int)n))
		{
			free_args(argv);
			free_all(a);
		}
		add_node(a, (int)n);
		i++;
	}
}
