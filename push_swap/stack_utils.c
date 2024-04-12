/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 08:46:24 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/12 15:36:09 by joandre-         ###   ########.fr       */
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

t_stack	*last_node(t_stack *a)
{
	if (a == NULL)
		return (NULL);
	while (a->next)
		a = a->next;
	return (a);
}

unsigned int	stack_size(t_stack *a)
{
	unsigned int	i;

	i = 0;
	while (a)
	{
		a = a->next;
		++i;
	}
	return (i);
}

void	free_stack(t_stack *a)
{
	t_stack	*b;

	while (a)
	{
		b = a;
		a = a->next;
		free(b);
		b = NULL;
	}
}

void	create_stack(t_stack **a, char **n, unsigned int i)
{
	t_stack	*new;
	t_stack	*last;

	while (n[i])
	{
		while (need_parse(n[i]))
			parse_2stack(a, n[i++]);
		if (n[i])
		{
			if (stack_size(*a))
			{
				new = create_node(ft_atoi(n[i++]));
				last = last_node(*a);
			}
			else
			{
				*a = create_node(ft_atoi(n[i++]));
				new = create_node(ft_atoi(n[i++]));
				last = last_node(*a);
			}
			new->prev = last;
			last->next = new;
		}
	}
}
