/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inst_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joandre- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/13 16:02:41 by joandre-          #+#    #+#             */
/*   Updated: 2024/04/20 02:32:58 by joandre-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "checker.h"

bool	exec_inst(t_stack **a, t_stack **b, char *i)
{
	if (i[0] == 's' && i[1] == 'a' && i[2] == '\n')
		csa(a);
	else if (i[0] == 's' && i[1] == 'b' && i[2] == '\n')
		csb(b);
	else if (i[0] == 's' && i[1] == 's' && i[2] == '\n')
		css(a, b);
	else if (i[0] == 'r' && i[1] == 'a' && i[2] == '\n')
		cra(a);
	else if (i[0] == 'r' && i[1] == 'b' && i[2] == '\n')
		crb(b);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == '\n')
		crr(a, b);
	else if (i[0] == 'p' && i[1] == 'a' && i[2] == '\n')
		cpa(b, a);
	else if (i[0] == 'p' && i[1] == 'b' && i[2] == '\n')
		cpb(a, b);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'a' && i[3] == '\n')
		crra(a);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'b' && i[3] == '\n')
		crrb(b);
	else if (i[0] == 'r' && i[1] == 'r' && i[2] == 'r' && i[3] == '\n')
		crrr(a, b);
	else
		return (false);
	return (true);
}

char	*parse_inst(char *inst)
{
	char	c[1];
	int		i;
	int		r;

	ft_bzero((char *)inst, 5);
	ft_bzero((char *)c, 1);
	i = 0;
	r = read(0, c, 1);
	while (r)
	{
		inst[i] = c[0];
		if (inst[i] == '\n')
			break ;
		if (i == 4)
		{
			while (r)
				r = read(0, c, 1);
			return (inst);
		}
		++i;
		r = read(0, c, 1);
	}
	if (r == 0 && inst[0] == '\0')
		return (NULL);
	return (inst);
}

static bool	get_result(t_stack **b, int f)
{
	if (stack_size(*b) || f)
	{
		free_stack(*b);
		free(b);
		if (f)
			write(2, "Error\n", 6);
		else
			write(1, "KO\n", 3);
		return (false);
	}
	free(b);
	return (true);
}

bool	get_inst(t_stack **a)
{
	t_stack	**b;
	char	inst[5];
	char	*cmd;
	int		f;

	b = malloc(sizeof(t_stack *));
	if (b == NULL)
		return (false);
	*b = NULL;
	f = 0;
	cmd = parse_inst(inst);
	while (cmd)
	{
		if (!exec_inst(a, b, cmd))
		{
			f = 1;
			break ;
		}
		cmd = parse_inst(inst);
	}
	return (get_result(b, f));
}
