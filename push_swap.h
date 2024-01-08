/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davda-si <davda-si@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 15:38:41 by davda-si          #+#    #+#             */
/*   Updated: 2023/11/17 18:27:14 by davda-si         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libs/libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_pswp
{
	int				nb;
	int				dex;
	int				cost;
	int				up_mid;
	int				cheap;
	struct s_pswp	*tgrt;
	struct s_pswp	*next;
	struct s_pswp	*prev;
}			t_pswp;

//main.c//
int		main(int argc, char **argv);
void	small_sort(t_pswp **a);

//stacks.c//
int		alr_sort(t_pswp *stack);
t_pswp	*find_big(t_pswp *stack);
t_pswp	*find_small(t_pswp *stack);
void	arrange(t_pswp **stack, t_pswp *top, char n);
int		ps_lstsize(t_pswp *lst);

//initstack_a.c//
void	initstack_a(t_pswp **a, char **argv);
void	check_first(char **argv);

//sort_it.c//
void	ft_index(t_pswp *stack);
void	sort_it(t_pswp **a, t_pswp **b);
void	init_n_a(t_pswp *a, t_pswp *b);
void	init_n_b(t_pswp *a, t_pswp *b);

//push.c//
void	pa(t_pswp **a, t_pswp **b);
void	pb(t_pswp **b, t_pswp **a);

//rotate.c & rrotate.c//
void	ra(t_pswp **a);
void	rb(t_pswp **b);
void	rr(t_pswp **a, t_pswp **b);
void	rra(t_pswp **a);
void	rrb(t_pswp **b);
void	rrr(t_pswp **a, t_pswp **b);

//swap.c//
void	sa(t_pswp **a);
void	sb(t_pswp **b);
void	ss(t_pswp **a, t_pswp **b);

//sort_utils.a//
void	move_ab(t_pswp **a, t_pswp **b);
void	cheap_n(t_pswp *stack);
void	check_cost_a(t_pswp *a, t_pswp *b);
void	target_a(t_pswp *a, t_pswp *b);
t_pswp	*get_cheap(t_pswp *stack);

//sort_utils.b//
void	target_b(t_pswp *a, t_pswp *b);
void	move_ba(t_pswp **a, t_pswp **b);
t_pswp	*ps_lstlast(t_pswp *lst);
void	rotation(t_pswp **a, t_pswp **b, t_pswp *ch_node, int flag);

//errors.c//
void	free_args(char	**args);
int		invalid(char *str);
int		dupl(t_pswp *a, int n);
void	free_s(t_pswp **stack);
void	free_all(t_pswp **stack);

#endif