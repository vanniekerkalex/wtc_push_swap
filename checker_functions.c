/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 13:19:37 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/30 18:24:40 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_stacks *s)
{
	int tmp;

	if (s->len_a > 1)
	{
		tmp = s->stack_a[s->len_a - 2];
		s->stack_a[s->len_a - 2] = s->stack_a[s->len_a - 1];
		s->stack_a[s->len_a - 1] = tmp;
	}
}

void	ft_swap_b(t_stacks *s)
{
	int tmp;

	if (s->len_b > 1)
	{
		tmp = s->stack_b[s->len_b - 2];
		s->stack_b[s->len_b - 2] = s->stack_b[s->len_b - 1];
		s->stack_b[s->len_b - 1] = tmp;
	}
}

void	ft_swap_ab(t_stacks *s)
{
	ft_swap_a(s);
	ft_swap_b(s);
}

void	ft_push_a(t_stacks *s)
{
	if (s->len_b > 0)
	{
		s->stack_a[s->len_a] = s->stack_b[s->len_b - 1];
		s->len_a++;
		s->len_b--;
	}
}

void	ft_push_b(t_stacks *s)
{
	if (s->len_a > 0)
	{
		s->stack_b[s->len_b] = s->stack_a[s->len_a - 1];
		s->len_b++;
		s->len_a--;
	}
}

void	ft_rotate_a(t_stacks *s)
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
}

void	ft_rotate_b(t_stacks *s)
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
}

void	ft_rotate_ab(t_stacks *s)
{
	ft_rotate_a(s);
	ft_rotate_b(s);
}

void	ft_rr_a(t_stacks *s)
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
}

void	ft_rr_b(t_stacks *s)
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
}

void	ft_rr_ab(t_stacks *s)
{
	ft_rr_a(s);
	ft_rr_b(s);
}
