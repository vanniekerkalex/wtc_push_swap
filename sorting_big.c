/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_big.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:16:57 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/04 16:11:10 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_blocks(t_stacks *s, int div, int sml)
{
	int i;
	int blocks;
	int c_min;

	blocks = (s->size / div);
	c_min = 0;
	while (s->len_a != 0)
	{
		c_min = 0;
		i = 0;
		while (i < s->len_a - 2)
			if (s->stack_a[s->len_a - 1] > s->stack_a[i++])
				c_min++;
		if (c_min < blocks + 1)
		{
			blocks--;
			ft_push_b(s, 1);
		}
		else
			ft_rr_a(s, 1);
		if (blocks <= sml)
			blocks = (s->size / div);
	}
}

void	ft_sort_v5(t_stacks *s)
{
	if (s->len_a < 101)
		ft_sort_blocks(s, 6, 1);
	else
		ft_sort_blocks(s, 10, 4);
	while (!ft_check_sorted(s) || s->len_b > 0)
	{
		if (ft_is_max(s->stack_b, s->len_b, s->stack_b[s->len_b - 1]))
			ft_push_a(s, 1);
		else if (ft_is_min(s->stack_b, s->len_b, s->stack_b[s->len_b - 1]))
		{
			ft_push_a(s, 1);
			ft_rotate_a(s, 1);
		}
		else if (ft_find_mm(s->stack_b, s->len_b) == 2)
			ft_rotate_b(s, 1);
		else
			ft_rr_b(s, 1);
		if (ft_check_sorted_b(s) && s->len_b > 0)
			while (s->len_b > 0)
				ft_push_a(s, 1);
		while (s->len_b == 0 && !ft_check_sorted(s))
			ft_rotate_a(s, 1);
	}
}
