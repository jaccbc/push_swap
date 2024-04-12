/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 07:40:17 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/12 22:03:03 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	throw_result(unsigned int i, int b, int argc)
{
	if (i && b)
	{
		write(2, "Error\n", 6);
		return (true);
	}
	else if (argc == 2 && i == 1)
		return (true);
	return (false);
}

static bool	just_one(int argc, char **argv)
{
	unsigned int	i;
	int				b;
	char			**splits;

	b = 0;
	i = 0;
	if (argv[1][0] == '\0')
		return (false);
	splits = ft_split(argv[1], ' ');
	while (splits[0][i] && (splits[0][i] == '-' || splits[0][i] == '+'
			|| ft_isdigit(splits[0][i])))
		++i;
	if (splits[0][i] || !int_check(ft_atol(splits[0])))
		b = 1;
	i = 0;
	while (splits[i])
		free(splits[i++]);
	free(splits);
	return (throw_result(i, b, argc));
}

static bool	input_check(int argc, char **argv, t_stack **a)
{
	int		i;
	char	**n;

	if (argv_check(argc, argv))
	{
		if (argc > 2)
			create_stack(a, argv, 1);
		else if (argc == 2)
		{
			n = ft_split(argv[1], ' ');
			create_stack(a, n, 0);
			i = 0;
			while (n[i])
				free(n[i++]);
			free(n);
		}
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
		return (1);
	if (just_one(argc, argv))
		return (1);
	a = malloc(sizeof(t_stack));
	if (a == NULL)
		return (2);
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
