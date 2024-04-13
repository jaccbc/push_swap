/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 04:02:35 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/13 22:52:23 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

static bool	check_split(char *s)
{
	unsigned int	i;
	unsigned int	d;

	i = 0;
	if (s[0] == '\0')
		return (false);
	if (s[i] == '-' || s[i] == '+')
		++i;
	if (s[i] == '\0')
		return (false);
	d = 0;
	while (ft_isdigit(s[i]) && d++ < 11)
		++i;
	if (s[i])
		return (false);
	return (true);
}

static bool	just_one(int argc, char **argv)
{
	unsigned int	i;
	int				b;
	char			**splits;

	b = 0;
	if (argv[1][0] == '\0')
		return (false);
	splits = ft_split(argv[1], ' ');
	if (!check_split(splits[0]) || !int_check(ft_atol(splits[0])))
		b = 1;
	i = 0;
	while (splits[i])
		free(splits[i++]);
	free(splits);
	if (i && b)
	{
		write(2, "Error\n", 6);
		return (true);
	}
	else if (argc == 2 && i == 1)
		return (true);
	return (false);
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
