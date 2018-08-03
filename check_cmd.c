/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:14:34 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:00:14 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_ccmd(char *l)
{
	if (!ft_strcmp(l, "sa") || !ft_strcmp(l, "sb") ||
		!ft_strcmp(l, "ss") || !ft_strcmp(l, "pa") ||
		!ft_strcmp(l, "pb") || !ft_strcmp(l, "ra") ||
		!ft_strcmp(l, "rb") || !ft_strcmp(l, "rr") ||
		!ft_strcmp(l, "rra") || !ft_strcmp(l, "rrb") ||
		!ft_strcmp(l, "rrr"))
		return (1);
	return (0);
}

void	ft_select_function(t_stacks *s, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_swap_a(s, 0);
	else if (ft_strcmp(str, "sb") == 0)
		ft_swap_b(s, 0);
	else if (ft_strcmp(str, "ss") == 0)
		ft_swap_ab(s, 0);
	else if (ft_strcmp(str, "pa") == 0)
		ft_push_a(s, 0);
	else if (ft_strcmp(str, "pb") == 0)
		ft_push_b(s, 0);
	else if (ft_strcmp(str, "ra") == 0)
		ft_rotate_a(s, 0);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rotate_b(s, 0);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rotate_ab(s, 0);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rr_a(s, 0);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rr_b(s, 0);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rr_ab(s, 0);
}

int		ft_is_dup (t_stacks *s)
{
	int i;
	int j;

	i = 0;
	while (i < s->size - 1)
	{
		j = i + 1;
		while (j < s->size)
		{
			if (s->stack_a[i] == s->stack_a[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
