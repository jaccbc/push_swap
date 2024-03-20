/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:46:24 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/17 04:12:28 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*create_node(int nbr)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (new)
	{
		new->prev = NULL;
		new->next = NULL;
		new->numb = nbr;
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

unsigned int	stack_size(t_stack *node)
{
	unsigned int	size;

	size = 0;
	while (node)
	{
		size++;
		node = node->next;
	}
	return (size);
}

void	free_stack(t_stack **node)
{
	t_stack	*linx;

	while (*node)
	{
		linx = *node;
		*node = (*node)->next;
		printf("[DEBUGGING][FREE_STACK][%p]=[%i] prev=[%p] next=[%p]\n",
			linx, linx->numb, linx->prev, linx->next);
		free(linx);
		linx = NULL;
	}
}

void	create_stack(t_stack **a, char **nbr, unsigned int i)
{
	t_stack	*new;
	t_stack	*last;

	if (*nbr == NULL)
		return ;
	last = create_node(ft_atoi(nbr[i++]));
	if (last)
	{
		*a = last;
		while (nbr[i])
		{
			new = create_node(ft_atoi(nbr[i++]));
			if (new)
			{
				last->next = new;
				new->prev = last;
				last = last->next;
			}
		}
	}
}
