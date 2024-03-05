/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:50:19 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/04 18:04:22 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	check_int(long long num)
{
	if (num <= INT_MAX && num >= INT_MIN)
		return (true);
	return (false);
}

long long	ft_atol(char *num)
{
	long long	n;
	long long	x;

	x = 1;
	if (*num == '-')
	{
		x *= -1;
		num++;
	}
	n = 0;
	while (*num >= '0' && *num <= '9')
	{
		n = n * 10 + (*num - '0');
		num++;
	}
	return (n * x);
}

bool	num_repeat(t_stack *a)
{
	t_stack	*check;
	t_stack	*repeat;

	if (a == NULL)
		return (false);
	check = a;
	while (check)
	{
		repeat = a;
		while (repeat)
		{
			if (check != repeat)
				if (check->numb == repeat->numb)
					return (true);
			repeat = repeat->next;
		}
		check = check->next;
	}
	return (false);
}
