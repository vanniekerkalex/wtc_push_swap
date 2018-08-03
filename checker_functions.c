/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:19:37 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:00:12 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *s, int flag) // Swaps top two elements
{
	int tmp;

	if (s->len_a > 1)
	{
		tmp = s->stack_a[s->len_a - 2];
		s->stack_a[s->len_a - 2] = s->stack_a[s->len_a - 1];
		s->stack_a[s->len_a - 1] = tmp;
		if (flag)
			write(1, "sa\n", 3);
	}
}

void	ft_swap_b(t_stacks *s, int flag) // Swaps top two elements
{
	int tmp;

	if (s->len_b > 1)
	{
		tmp = s->stack_b[s->len_b - 2];
		s->stack_b[s->len_b - 2] = s->stack_b[s->len_b - 1];
		s->stack_b[s->len_b - 1] = tmp;
		if (flag)
			write(1, "sb\n", 3);
	}
}

void	ft_swap_ab(t_stacks *s, int flag) // Swaps top two elements of both stacks
{
	ft_swap_a(s, 1);
	ft_swap_b(s, 1);
	if (flag)
		write(1,"ss\n",3);
}

void	ft_push_a(t_stacks *s, int flag) // Push top element from B to A
{
	if (s->len_b > 0)
	{
		s->stack_a[s->len_a] = s->stack_b[s->len_b - 1];
		s->len_a++;
		s->len_b--;
		if (flag)
		write(1, "pa\n", 3);
	}
}

void	ft_push_b(t_stacks *s, int flag) // Push top element from A to B
{
	if (s->len_a > 0)
	{
		s->stack_b[s->len_b] = s->stack_a[s->len_a - 1];
		s->len_b++;
		s->len_a--;
		if (flag)
			write(1, "pb\n", 3);
	}
}
