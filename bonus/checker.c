/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:02:35 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/20 02:26:02 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

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
		if (get_inst(a))
		{
			if (sort_check(*a))
				write(1, "OK\n", 3);
			else
				write(1, "KO\n", 3);
		}
		free_stack(*a);
	}
	else
		write(2, "Error\n", 6);
	free(a);
	return (0);
}
