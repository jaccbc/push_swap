/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numb_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:50:19 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/17 04:43:20 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	int_check(long long nbr)
{
	if (nbr <= INT_MAX && nbr >= INT_MIN)
		return (true);
	return (false);
}

long long	ft_atol(char *nbr)
{
	long long	n;
	long long	x;

	x = 1;
	if (*nbr == '-')
	{
		x *= -1;
		nbr++;
	}
	n = 0;
	while (*nbr >= '0' && *nbr <= '9')
	{
		n = n * 10 + (*nbr - '0');
		nbr++;
	}
	return (n * x);
}

bool	numb_repeat(t_stack *a)
{
	t_stack	*repeat;

	if (a == NULL)
		return (false);
	while (a)
	{
		repeat = a;
		while (repeat)
		{
			if (a != repeat)
				if (a->numb == repeat->numb)
					return (true);
			repeat = repeat->next;
		}
		a = a->next;
	}
	return (false);
}
