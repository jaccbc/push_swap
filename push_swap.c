/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:40:17 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/03 00:37:26 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	input_check(int argc, char **argv, t_stack **stack_a)
{
	int	i;

	i = 1;
	if (argv_check(argc, argv, stack_a))
	{
		if (argc > 2)
		{
			while (argc > i)
				create_stack(stack_a, ft_atol(argv[i++]));
		}
	}
	if (numb_repeat(*stack_a))
	{
		write(2, "Error\n", 6);
		return (false);
	}
	return (true);
}

int	main(int argc, char **argv)
{
	t_stack	**stack_a;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	stack_a = (t_stack **)malloc(sizeof(t_stack));
	if (stack_a == NULL)
		return (2);
	*stack_a = NULL;
	if (input_check(argc, argv, stack_a))
		write(1, "[TRUE]\n", 7);
	free_stack(stack_a);
	free(stack_a);
	return (0);
}
