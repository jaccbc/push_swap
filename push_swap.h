/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/03 01:00:36 by joandre-         ###   ########.fr       */
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

void		sa(t_stack **node);
void		sb(t_stack **node);
void		ss(t_stack **a, t_stack **b);
void		pa(t_stack **b, t_stack **a);
void		pb(t_stack **a, t_stack **b);
void		ra(t_stack **node);
void		rb(t_stack **node);
void		rr(t_stack **a, t_stack **b);
void		rra(t_stack **node);
void		rrb(t_stack **node);
void		rrr(t_stack **a, t_stack **b);
t_stack		*last_node(t_stack *node);
void		create_stack(t_stack **node, int n);
void		free_stack(t_stack **node);
long long	ft_atol(char *number);
bool		numb_repeat(t_stack *stack_a);
bool		argv_check(int argc, char **argv, t_stack **node);
#endif
