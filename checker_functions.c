/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:19:37 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/01 16:27:39 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *s) // Swaps top two elements
{
	int tmp;

	if (s->len_a > 1)
	{
		tmp = s->stack_a[s->len_a - 2];
		s->stack_a[s->len_a - 2] = s->stack_a[s->len_a - 1];
		s->stack_a[s->len_a - 1] = tmp;
	}
	write(1,"SA\n",3);
}

void	ft_swap_b(t_stacks *s) // Swaps top two elements
{
	int tmp;

	if (s->len_b > 1)
	{
		tmp = s->stack_b[s->len_b - 2];
		s->stack_b[s->len_b - 2] = s->stack_b[s->len_b - 1];
		s->stack_b[s->len_b - 1] = tmp;
	}
	write(1,"SB\n",3);
}

void	ft_swap_ab(t_stacks *s) // Swaps top two elements of both stacks
{
	ft_swap_a(s);
	ft_swap_b(s);
	write(1,"SS\n",3);
}

void	ft_push_a(t_stacks *s) // Push top element from B to A
{
	if (s->len_b > 0)
	{
		s->stack_a[s->len_a] = s->stack_b[s->len_b - 1];
		s->len_a++;
		s->len_b--;
	}
	write(1,"PA\n",3);
}

void	ft_push_b(t_stacks *s) // Push top element from A to B
{
	if (s->len_a > 0)
	{
		s->stack_b[s->len_b] = s->stack_a[s->len_a - 1];
		s->len_b++;
		s->len_a--;
	}
	write(1,"PB\n",3);
}
