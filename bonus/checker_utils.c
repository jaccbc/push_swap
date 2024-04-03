/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/02 20:01:42 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/02 20:03:43 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

void	checker_sort_order(t_stack **a)
{
	if (index_numb(*a, min(*a)) <= stack_size(*a) / 2)
	{
		while (index_numb(*a, min(*a)))
			cra(a);
	}
	else
	{
		while (index_numb(*a, max(*a)) != stack_size(*a) - 1)
			crra(a);
	}
}
