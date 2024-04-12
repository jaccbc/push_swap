/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argv_parse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 16:57:25 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/12 20:33:44 by joandre-         ###   ########.fr       */
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
