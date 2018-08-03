/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:38:02 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:00:11 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stacks *s, int flag) // Shift all elements up (top becomes bottom)
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
		if (flag)
			write(1, "ra\n", 3);
	}
}

void	ft_rotate_b(t_stacks *s, int flag) // Shift all elements up (top becomes bottom)
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
		if (flag)
			write(1, "rb\n", 3);
	}
}

void	ft_rotate_ab(t_stacks *s, int flag) // Shift all elements up (top becomes bottom) - Both.
{
	ft_rotate_a(s, 1);
	ft_rotate_b(s, 1);
	if (flag)
		write(1,"rr\n",3);
}
