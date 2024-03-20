/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_algo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:53:25 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/20 04:25:04 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static void	sort_plus(t_stack **a)
{
	t_stack	**b;

	b = malloc(sizeof(t_stack));
	if (b == NULL)
		return ;
	*b = NULL;
	while (stack_size(*b) != 3)
		pb(a, b);
	sort_3b(b);
	while (stack_size(*a))
		sort_2b(a, b);
	while (stack_size(*b))
		pa(b, a);
	free(b);
}

void	sort_algo(t_stack **a)
{
	if (sort_check(*a))
		return ;
	if (stack_size(*a) == 3)
		sort_3(a);
	else
		sort_plus(a);
}
