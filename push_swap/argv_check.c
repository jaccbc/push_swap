/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:04:29 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/13 22:48:30 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	check_string(int argc, char **argv)
{
	int				c;
	unsigned int	i;
	unsigned int	d;

	c = 1;
	i = 0;
	while (c < argc)
	{
		if (argv[c][i] == '\0')
			return (false);
		if (argv[c][i] == '-' || argv[c][i] == '+')
			if (argv[c][++i] == '\0' || ft_isdigit(argv[c][i]) == 0)
				return (false);
		d = 0;
		while (ft_isdigit(argv[c][i]) && d++ < 11)
			++i;
		if (argv[c][i++] == ' ')
			continue ;
		if (argv[c++][--i])
			return (false);
		i = 0;
	}
	return (true);
}

static bool	check_string_int(char **argv)
{
	bool			result;
	char			**splits;
	unsigned int	i;

	result = true;
	splits = ft_split(argv[1], ' ');
	i = 0;
	while (result && splits[i])
	{
		result = int_check(ft_atol(splits[i]));
		free(splits[i++]);
	}
	free(splits);
	return (result);
}

static bool	argc_plus2(int argc, char **argv)
{
	int		i;
	bool	result;

	i = 1;
	result = true;
	if (check_string(argc, argv))
	{
		while (argc > i && result)
		{
			if (need_parse(argv[i]))
			{
				if (!check_parse(argv[i++]))
					return (false);
			}
			else
				result = int_check(ft_atol(argv[i++]));
		}
	}
	else
		return (false);
	return (result);
}

bool	argv_check(int argc, char **argv)
{
	if (argv[1][0] == '\0')
		return (false);
	if (argc == 2)
	{
		if (check_string(argc, argv))
			return (check_string_int(argv));
	}
	return (argc_plus2(argc, argv));
}
