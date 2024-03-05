/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:40:17 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/05 03:52:21 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	input_check(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**nums;

	if (argv_check(argc, argv))
	{
		if (argc > 2)
			create_stack(a, argv, 1);
		else if (argc == 2)
		{
			nums = ft_split(argv[1], ' ');
			create_stack(a, nums, 0);
			i = 0;
			while (nums[i])
				free(nums[i++]);
			free(nums);
		}
		if (num_repeat(*a) || stack_size(*a) < 3)
		{
			free_stack(a);
			return (false);
		}
		return (true);
	}
	return (false);
}

int	main(int argc, char **argv)
{
	t_stack	**a;

	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	a = (t_stack **)malloc(sizeof(t_stack));
	if (a == NULL)
		return (2);
	if (input_check(argc, argv, a))
	{
		sort_algo(a);
		free_stack(a);
	}
	else
		write(2, "Error\n", 6);
	return (0);
}
