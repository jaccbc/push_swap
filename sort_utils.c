/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/20 04:29:36 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	sort_check(t_stack *a)
{
	while (a->numb < a->next->numb)
	{
		a = a->next;
		if (a->next == NULL)
			return (true);
	}
	return (false);
}

void	sort_3(t_stack **a)
{
	t_stack	*mid;

	mid = (*a)->next;
	if (mid->numb > mid->prev->numb)
	{
		if (mid->prev->numb < mid->next->numb)
		{
			sa(a);
			ra(a);
		}
		else
			rra(a);
	}
	else if (mid->prev->numb > mid->next->numb)
	{
		if (mid->numb > mid->next->numb)
		{
			ra(a);
			sa(a);
		}
		else
			ra(a);
	}
	else
		sa(a);
}

void	sort_3b(t_stack **b)
{
	t_stack	*mid;

	mid = (*b)->next;
	if (mid->numb < mid->prev->numb)
	{
		if (mid->prev->numb > mid->next->numb)
		{
			sa(b);
			ra(b);
		}
		else
			rra(b);
	}
	else if (mid->prev->numb < mid->next->numb)
	{
		if (mid->numb < mid->next->numb)
		{
			ra(b);
			sa(b);
		}
		else
			ra(b);
	}
	else
		sa(b);
}

static void	sort_control(unsigned int i, unsigned int t,
	t_stack **a, t_stack **b)
{
	unsigned int	a_mid;
	unsigned int	b_mid;

	a_mid = stack_size(*a) / 2;
	b_mid = stack_size(*b) / 2;
	if (i > a_mid && t > b_mid)
		sort_reverse(i, t, a, b);
	if (i <= a_mid && t <= b_mid)
		sort_rotate(i, t, a, b);
	if (i > a_mid && t <= b_mid)
		sort_revrotate(i, t, a, b);
	if (i <= a_mid && t > b_mid)
		sort_rotreverse(i, t, a, b);
}

void	sort_2b(t_stack **a, t_stack **b)
{
	unsigned int	i;
	unsigned int	index;
	t_stack			*tmp;

	index = cheap_index(*a, *b);
	tmp = *a;
	i = 0;
	while (i < index)
	{
		i++;
		tmp = tmp->next;
	}
	sort_control(index, index_target(*b, tmp->numb), a, b);
}
