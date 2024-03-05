/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/05 03:46:53 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	int				numb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

void		sa(t_stack **a);
void		sb(t_stack **b);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **a);
void		rb(t_stack **b);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **a);
void		rrb(t_stack **b);
void		rrr(t_stack **a, t_stack **b);
t_stack		*create_node(int n);
t_stack		*last_node(t_stack *node);
size_t		stack_size(t_stack *node);
void		create_stack(t_stack **node, char **nums, int i);
void		free_stack(t_stack **node);
bool		check_int(long long num);
long long	ft_atol(char *num);
bool		num_repeat(t_stack *a);
bool		argv_check(int argc, char **argv);
bool		sort_check(t_stack *a);
void		sort_3(t_stack **a);
void		sort_algo(t_stack **a);
#endif
