/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:40:17 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/20 01:43:18 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	input_check(int argc, char **argv, t_stack **a)
{
	if (argv_check(argc, argv))
	{
		create_stack(a, argv, 1);
		if (int_repeat(*a))
		{
			free_stack(*a);
			return (false);
		}
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack	**a;

	if (argc == 1)
		return (0);
	a = malloc(sizeof(t_stack *));
	if (a == NULL)
		return (1);
	*a = NULL;
	if (input_check(argc, argv, a))
	{
		if (stack_size(*a) == 2 && !sort_check(*a))
			sa(a);
		else
			sort_algo(a);
		free_stack(*a);
	}
	else
		write(2, "Error\n", 6);
	free(a);
	return (0);
}
