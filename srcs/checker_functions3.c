/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:38:27 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/07 12:20:26 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rr_a(t_stacks *s, int flag, int p_flag)
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
		if (p_flag)
			print_win(s, flag);
	}
}

void	ft_rr_b(t_stacks *s, int flag, int p_flag)
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
		if (p_flag)
			print_win(s, flag);
	}
}

void	ft_rr_ab(t_stacks *s, int flag, int p_flag)
{
	ft_rr_a(s, 1, p_flag);
	ft_rr_b(s, 1, p_flag);
	if (flag)
		write(1, "rrr\n", 4);
	if (p_flag)
		print_win(s, flag);
}
