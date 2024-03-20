/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:04:29 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/20 04:28:32 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

static bool	check_unquote(int argc, char **argv)
{
	int	c;
	int	i;

	c = 1;
	while (c < argc)
	{
		i = 0;
		if (argv[c][i] == '-')
		{
			i++;
			if (argv[c][i] == '0')
				return (false);
		}
		while (ft_isdigit(argv[c][i]))
			i++;
		if (argv[c][i])
			return (false);
		c++;
	}
	return (true);
}

static bool	check_quote(char **argv)
{
	int	i;

	i = 0;
	while (argv[1][i])
	{
		if (argv[1][i] == '-')
		{
			if (argv[1][++i] == '0')
				return (false);
		}
		while (ft_isdigit(argv[1][i]))
			i++;
		if (argv[1][i] == ' ')
			i++;
		else
			break ;
	}
	if (argv[1][i])
		return (false);
	return (true);
}

static bool	check_quote_int(char **argv)
{
	bool	result;
	char	**splits;
	size_t	i;

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

bool	argv_check(int argc, char **argv)
{
	bool	result;
	int		i;

	i = 1;
	if (argc == 2)
	{
		result = check_quote(argv);
		if (result)
			result = check_quote_int(argv);
	}
	else if (argc > 2)
	{
		result = check_unquote(argc, argv);
		if (result)
			while (argc > i && result)
				result = int_check(ft_atol(argv[i++]));
	}
	return (result);
}
