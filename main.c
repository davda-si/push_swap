/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 16:35:47 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/17 18:51:22 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	small_sort(t_pswp **a)
{
	t_pswp	*big;

	big = find_big(*a);
	if (big == *a)
		ra(a);
	else if ((*a)->next == big)
		rra(a);
	if ((*a)->nb > (*a)->next->nb)
		sa(a);
}

static char	**ft_cut(char **argv)
{
	int		i;
	char	*temp;
	char	*temp2;
	char	**res;

	i = 0;
	temp = calloc(2, 1);
	while (argv[i])
	{
		temp2 = ft_strjoin(temp, argv[i]);
		free(temp);
		temp = ft_strjoin(temp2, " ");
		free(temp2);
		i++;
	}
	res = ft_split(temp, ' ');
	free(temp);
	return (res);
}

int	main(int argc, char **argv)
{
	t_pswp		*a;
	t_pswp		*b;
	char		**args;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	args = ft_cut(argv + 1);
	initstack_a(&a, args);
	if (!alr_sort(a))
	{
		if (ps_lstsize(a) == 2)
			sa(&a);
		else if (ps_lstsize(a) == 3)
			small_sort(&a);
		else
			sort_it(&a, &b);
	}
	free_s(&a);
	free_args(args);
	return (0);
}
