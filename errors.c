/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 19:04:24 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/17 18:46:41 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	invalid(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = ft_strlen(str);
	if ((str[i] == '-' && str[i + 1] == '0') || (str[i] == '+' 
			&& str[i + 1] == '0'))
		return (1);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	dupl(t_pswp *a, int n)
{
	if (!a)
		return (0);
	while (a)
	{
		if (a->nb == n)
			return (1);
		a = a->next;
	}
	return (0);
}

void	free_s(t_pswp **stack)
{
	t_pswp	*tmp;
	t_pswp	*cur;

	if (!stack)
		return ;
	cur = *stack;
	while (cur)
	{
		tmp = cur->next;
		free(cur);
		cur = tmp;
	}
	*stack = NULL;
}

void	free_all(t_pswp **stack)
{
	free_s(stack);
	ft_printf("There was an error, try again\n");
	exit (1);
}

void	free_args(char	**args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}
