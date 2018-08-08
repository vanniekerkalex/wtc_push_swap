/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:50:29 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/08 12:02:45 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate_a(t_stacks *s, int flag, int p_flag)
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
		if (p_flag)
			print_win(s, flag, p_flag);
	}
}

void	ft_rotate_b(t_stacks *s, int flag, int p_flag)
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
		if (p_flag)
			print_win(s, flag, p_flag);
	}
}

void	ft_rotate_ab(t_stacks *s, int flag, int p_flag)
{
	ft_rotate_a(s, flag, p_flag);
	ft_rotate_b(s, flag, p_flag);
	if (flag)
		write(1, "rr\n", 3);
	if (p_flag)
		print_win(s, flag, p_flag);
}
