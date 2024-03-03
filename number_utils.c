/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   number_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 19:50:19 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/03 00:34:57 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

long long	ft_atol(char *number)
{
	long long	n;
	long long	x;

	x = 1;
	if (*number == '-')
	{
		x *= -1;
		number++;
	}
	n = 0;
	while (*number >= '0' && *number <= '9')
	{
		n = n * 10 + (*number - '0');
		number++;
	}
	return (n * x);
}

bool	numb_repeat(t_stack *stack_a)
{
	t_stack	*check;
	t_stack	*repeat;

	if (stack_a == NULL)
		return (false);
	check = stack_a;
	while (check)
	{
		repeat = stack_a;
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
