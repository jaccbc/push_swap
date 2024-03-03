/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:46:24 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/02 21:30:19 by joandre-         ###   ########.fr       */
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

void	free_stack(t_stack **node_stack)
{
	t_stack	*linx;

	linx = *node_stack;
	while (linx)
	{
		*node_stack = (*node_stack)->next;
		free(linx);
		linx = *node_stack;
	}
}

void	create_stack(t_stack **node_stack, int n)
{
	t_stack	*new;
	t_stack	*last;

	new = create_node(n);
	if (*node_stack == NULL)
	{
		*node_stack = new;
		return ;
	}
	if (new)
	{
		last = last_node(*node_stack);
		last->next = new;
		new->prev = last;
	}
}
