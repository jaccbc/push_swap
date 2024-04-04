/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 10:49:05 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 03:11:14 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

void	debug_stack(t_stack *a, t_stack *b)
{
	unsigned int	i;

	i = 0;
	printf("\n[DEBUG_STACK] STACK A\n");
	while (a)
	{
		printf("numb=[%i] index=[%u] addr=[%p] prev=[%p] next=[%p]\n",
			a->numb, i, a, a->prev, a->next);
		a = a->next;
		++i;
	}
	i = 0;
	printf("[DEBUG_STACK] STACK B\n");
	while (b)
	{
		printf("numb=[%i] index=[%u] addr=[%p] prev=[%p] next=[%p]\n",
			b->numb, i, b, b->prev, b->next);
		b = b->next;
		++i;
	}
}
