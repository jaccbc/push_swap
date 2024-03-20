/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 15:32:44 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/20 04:02:41 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

unsigned int	index_numb(t_stack *a, int nbr)
{
	unsigned int	i;

	i = 0;
	while (nbr != a->numb)
	{
		i++;
		a = a->next;
	}
	return (i);
}

unsigned int	index_target(t_stack *b, int nbr)
{
	unsigned int	i;

	i = 0;
	while (b)
	{
		if (nbr > b->numb)
			break ;
		b = b->next;
		i++;
	}
	return (i);
}

static unsigned int	index_calc(unsigned int a, unsigned int b,
	unsigned int i, unsigned int t)
{
	unsigned int	cost;
	unsigned int	a_mid;
	unsigned int	b_mid;

	a_mid = a / 2;
	b_mid = b / 2;
	if (i > a_mid)
		cost = a - i;
	else
		cost = i;
	if (t == b && i < a_mid)
		cost += 1;
	if (t > b_mid)
		cost += b - t;
	else if (t == b && i < a_mid)
		cost += 1;
	else
		cost += t;
	if (i == t)
		cost = i;
	return (cost);
}

unsigned int	cheap_index(t_stack *a, t_stack *b)
{
	unsigned int	size_a;
	unsigned int	size_b;
	unsigned int	cheap;

	size_a = stack_size(a);
	size_b = stack_size(b);
	cheap = index_calc(size_a, size_b,
			index_numb(a, a->numb), index_target(b, a->numb));
	while (a)
	{
		if (cheap > index_calc(size_a, size_b,
				index_numb(a, a->numb), index_target(b, a->numb)))
		{
			cheap = index_numb(a, a->numb);
		}
		a = a->next;
	}
	return (cheap);
}
