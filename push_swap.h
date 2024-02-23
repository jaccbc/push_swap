/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/02/23 20:58:34 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"

typedef struct s_stack
{
	int				numb;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

t_stack	*last_node(t_stack *node);
void	sa(t_stack **node);
void	sb(t_stack **node);
void	ss(t_stack **a, t_stack **b);
void	pa(t_stack **b, t_stack **a);
void	pb(t_stack **a, t_stack **b);
void	ra(t_stack **node);
void	rb(t_stack **node);
void	rr(t_stack **a, t_stack **b);
void	rra(t_stack **node);
void	rrb(t_stack **node);
void	rrr(t_stack **a, t_stack **b);
#endif
