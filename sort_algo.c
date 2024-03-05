/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:53:25 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/05 03:44:53 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

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

void	sort_algo(t_stack **a)
{
	if (sort_check(*a))
		return ;
	if (stack_size(*a) == 3)
		sort_3(a);
}
