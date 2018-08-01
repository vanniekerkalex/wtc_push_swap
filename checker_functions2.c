/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:38:02 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/01 16:28:00 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stacks *s) // Shift all elements up (top becomes bottom)
{
	int tmp;
	int i;

	if (s->len_a > 1)
	{
		i = s->len_a - 1;
		tmp = s->stack_a[s->len_a - 1];
		while (i > 0)
		{
			s->stack_a[i] = s->stack_a[i - 1];
			i--;
		}
		s->stack_a[0] = tmp;
	}
	write(1,"RA\n",3);
}

void	ft_rotate_b(t_stacks *s) // Shift all elements up (top becomes bottom)
{
	int tmp;
	int i;

	if (s->len_b > 1)
	{
		i = s->len_b - 1;
		tmp = s->stack_b[s->len_b - 1];
		while (i > 0)
		{
			s->stack_b[i] = s->stack_b[i - 1];
			i--;
		}
		s->stack_b[0] = tmp;
	}
	write(1,"RB\n",3);
}

void	ft_rotate_ab(t_stacks *s) // Shift all elements up (top becomes bottom) - Both.
{
	ft_rotate_a(s);
	ft_rotate_b(s);
	write(1,"RR\n",3);
}
