/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:46:24 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/02 11:05:40 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static t_stack	*create_node(int n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->prev = NULL;
		new->next = NULL;
		new->numb = n;
	}
	return (new);
}

t_stack	*last_node(t_stack *node)
{
	if (node == NULL)
		return (NULL);
	while (node->next)
		node = node->next;
	return (node);
}

void	free_stack(t_stack **node)
{
	t_stack	*linx;

	linx = *node;
	while (linx)
	{
		*node = (*node)->next;
		free(linx);
		linx = *node;
	}
}

void	create_stack(t_stack **stack_a, int n)
{
	t_stack	*new;
	t_stack	*last;

	new = create_node(n);
	if (*stack_a == NULL)
	{
		*stack_a = new;
		return ;
	}
	if (new)
	{
		last = last_node(*stack_a);
		last->next = new;
		new->prev = last;
	}
}
