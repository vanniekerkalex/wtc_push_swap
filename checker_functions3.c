/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:38:27 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:00:09 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_a(t_stacks *s, int flag) // Shifts all elements down (bottom becomes top)
{
	int tmp;
	int i;

	if (s->len_a > 1)
	{
		i = 0;
		tmp = s->stack_a[0];
		while (i < s->len_a - 1)
		{
			s->stack_a[i] = s->stack_a[i + 1];
			i++;
		}
		s->stack_a[s->len_a - 1] = tmp;
		if (flag)
			write(1, "rra\n", 4);
	}
}

void	ft_rr_b(t_stacks *s, int flag) // Shifts all elements down (bottom becomes top)
{
	int tmp;
	int i;

	if (s->len_b > 1)
	{
		i = 0;
		tmp = s->stack_b[0];
		while (i < s->len_b - 1)
		{
			s->stack_b[i] = s->stack_b[i + 1];
			i++;
		}
		s->stack_b[s->len_b - 1] = tmp;
		if (flag)
			write(1, "rrb\n", 4);
	}
}

void	ft_rr_ab(t_stacks *s, int flag) // Shifts all elements down (bottom becomes top) - Both
{
	ft_rr_a(s, 1);
	ft_rr_b(s, 1);
	if (flag)
		write(1,"rrr\n",4);
}
