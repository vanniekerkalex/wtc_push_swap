/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_small.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:09:04 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/07 15:09:18 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_find_mm(int *arr, int len)
{
	int i;
	int min;
	int max;
	int val;

	val = 1;
	min = 0;
	max = 0;
	i = 0;
	while (i < len)
	{
		(ft_is_max(arr, len, arr[i])) && (max = i);
		(ft_is_min(arr, len, arr[i])) && (min = i);
		i++;
	}
	if (ft_abs(len / 2, max) > ft_abs(len / 2, min))
		(max < len / 2) ? (val) : (val = 2);
	else
		(min < len / 2) ? (val) : (val = 2);
	return (val);
}

void	ft_sort(t_stacks *s, int l_b, int p_flag)
{
	if (!ft_check_sorted(s) || s->len_b > l_b)
	{
		while (!ft_check_sorted(s) || s->len_b > l_b)
		{
			if (ft_is_min(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
				ft_push_b(s, 1, p_flag);
			else if (ft_is_max(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
				ft_rr_a(s, 1, p_flag);
			else if (s->stack_a[s->len_a - 1] > s->stack_a[s->len_a - 2])
				ft_swap_a(s, 1, p_flag);
			else
				ft_rr_a(s, 1, p_flag);
			while (ft_check_sorted(s) && s->len_b > l_b)
				ft_push_a(s, 1, p_flag);
		}
	}
}

void	ft_sort_3(t_stacks *s, int l_b, int p_flag)
{
	if (!ft_check_sorted(s))
	{
		if (ft_is_min(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
		{
			ft_swap_a(s, 1, p_flag);
			ft_rotate_a(s, 1, p_flag);
		}
		else if (ft_is_max(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
		{
			ft_rotate_a(s, 1, p_flag);
			if (!ft_check_sorted(s))
				ft_swap_a(s, 1, p_flag);
		}
		else
			ft_sort(s, l_b, p_flag);
	}
}

void	ft_sort_4(t_stacks *s, int p_flag)
{
	if (!ft_check_sorted(s))
	{
		if (ft_is_min(s->stack_a, s->len_a, s->stack_a[s->len_a - 1])
				|| ft_is_max(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
		{
			ft_push_b(s, 1, p_flag);
			ft_sort_3(s, 1, p_flag);
			ft_push_a(s, 1, p_flag);
			if (ft_is_max(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
				ft_rotate_a(s, 1, p_flag);
		}
		else
			ft_sort(s, 0, p_flag);
	}
}

void	ft_free(t_stacks *s)
{
	free(s->stack_a);
	s->stack_a = NULL;
	free(s->stack_b);
	s->stack_b = NULL;
	free(s);
}
