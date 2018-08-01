/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:38:27 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/01 16:28:24 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_a(t_stacks *s) // Shifts all elements down (bottom becomes top)
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
	}
	write(1,"RRA\n",4);
}

void	ft_rr_b(t_stacks *s) // Shifts all elements down (bottom becomes top)
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
	}
	write(1,"RRB\n",4);
}

void	ft_rr_ab(t_stacks *s) // Shifts all elements down (bottom becomes top) - Both
{
	ft_rr_a(s);
	ft_rr_b(s);
	write(1,"RRR\n",4);
}
