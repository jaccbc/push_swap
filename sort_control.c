/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 02:26:14 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/20 04:25:30 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	sort_reverse(unsigned int i, unsigned int t, t_stack **a, t_stack **b)
{
	unsigned int	size_a;
	unsigned int	size_b;

	size_a = stack_size(*a);
	size_b = stack_size(*b);
	while (i < size_a && t < size_b)
	{
		rrr(a, b);
		++i;
		++t;
	}
	while (i < size_a)
	{
		rra(a);
		++i;
	}
	while (t < size_b)
	{
		rrb(b);
		++t;
	}
}

void	sort_rotate(unsigned int i, unsigned int t, t_stack **a, t_stack **b)
{
	while (i && t)
	{
		rrr(a, b);
		--i;
		--t;
	}
	while (i)
	{
		rra(a);
		--i;
	}
	while (t)
	{
		rrb(b);
		--t;
	}
}

void	sort_revrotate(unsigned int i, unsigned int t, t_stack **a, t_stack **b)
{
	unsigned int	size;

	size = stack_size(*a);
	while (i < size)
	{
		rra(a);
		++i;
	}
	while (t)
	{
		rb(b);
		--t;
	}
}

void	sort_rotreverse(unsigned int i, unsigned int t,
	t_stack **a, t_stack **b)
{
	unsigned int	size;

	size = stack_size(*b);
	while (i)
	{
		ra(a);
		--i;
	}
	while (t < size)
	{
		rrb(b);
		++t;
	}
}
