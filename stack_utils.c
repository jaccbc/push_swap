/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:46:24 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/05 03:46:39 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

t_stack	*create_node(int n)
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

size_t	stack_size(t_stack *node)
{
	size_t	size;

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
		free(linx);
	}
	free(node);
}

void	create_stack(t_stack **node, char **nums, int i)
{
	t_stack	*new;
	t_stack	*last;

	last = create_node(ft_atoi(nums[i++]));
	if (last)
	{
		*node = last;
		while (nums[i])
		{
			new = create_node(ft_atoi(nums[i++]));
			if (new)
			{
				last->next = new;
				new->prev = last;
				last = last->next;
			}
		}
	}
}
