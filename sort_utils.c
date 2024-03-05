/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 19:57:00 by joandre-          #+#    #+#             */
/*   Updated: 2024/03/05 03:42:09 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

bool	sort_check(t_stack *a)
{
	while (a->numb < a->next->numb)
	{
		a = a->next;
		if (a->next == NULL)
			return (true);
	}
	return (false);
}
