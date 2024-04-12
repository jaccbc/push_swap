/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:04:29 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/12 15:37:22 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	check_unquote(int argc, char **argv)
{
	int				c;
	unsigned int	i;

	c = 1;
	i = 0;
	while (c < argc)
	{
		if (argv[c][0] == '\0')
			return (false);
		if (argv[c][i] == '-' || argv[c][i] == '+')
			++i;
		while (ft_isdigit(argv[c][i]))
			++i;
		if (argv[c][i] == ' ')
		{
			++i;
			continue ;
		}
		if (argv[c++][i])
			return (false);
		i = 0;
	}
	return (true);
}

static bool	check_quote(char **argv)
{
	unsigned int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-')
		{
			if (argv[1][++i] == '0')
				return (false);
		}
		while (ft_isdigit(argv[1][i]))
			++i;
		if (argv[1][i] == ' ')
		{
			++i;
			continue ;
		}
		else
			break ;
	}
	if (argv[1][i])
		return (false);
	return (true);
}

static bool	check_quote_int(char **argv)
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
	if (check_unquote(argc, argv))
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
	if (argc == 2)
	{
		if (check_quote(argv))
			return (check_quote_int(argv));
	}
	return (argc_plus2(argc, argv));
}
