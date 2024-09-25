/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 00:04:29 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/20 01:33:19 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	need_parse(char *s)
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (false);
	while (s[i])
	{
		if (s[i++] == ' ')
			return (true);
	}
	return (false);
}

bool	check_parse(char *s)
{
	unsigned int	i;
	char			**splits;
	bool			result;

	result = true;
	splits = ft_split(s, ' ');
	if (!splits)
		return (false);
	i = 0;
	while (result && splits[i])
	{
		result = int_check(ft_atol(splits[i]));
		free(splits[i++]);
	}
	while (splits[i])
		free(splits[i++]);
	free(splits);
	return (result);
}

void	parse_2stack(t_stack **a, char *s)
{
	t_stack			*new;
	unsigned int	i;
	char			**splits;

	i = 0;
	splits = ft_split(s, ' ');
	if (!splits)
		return ;
	if (*a == NULL)
	{
		*a = create_node(ft_atoi(splits[i]));
		free(splits[i++]);
	}
	while (splits[i])
	{
		new = create_node(ft_atoi(splits[i]));
		if (new)
		{
			new->prev = last_node(*a);
			last_node(*a)->next = new;
		}
		free(splits[i++]);
	}
	free(splits);
}

static bool	check_string(int argc, char **argv)
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
			if (argv[c][++i] == '\0' || !ft_isdigit(argv[c][i]))
				return (false);
		while (ft_isdigit(argv[c][i]))
			++i;
		if (argv[c][i++] == ' ')
			continue ;
		if (argv[c++][--i])
			return (false);
		i = 0;
	}
	return (true);
}

bool	argv_check(int argc, char **argv)
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
