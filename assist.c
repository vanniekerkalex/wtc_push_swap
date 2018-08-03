/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assist.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/03 17:12:08 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:26:24 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_check_sorted_b(t_stacks *s)
{
	int i;

	i = 0;
	while (i < s->len_b - 1)
	{
		if (s->stack_b[i + 1] < s->stack_b[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_min(int *arr, int len, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (num > arr[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_is_max(int *arr, int len, int num)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (num < arr[i])
			return (0);
		i++;
	}
	return (1);
}

int		ft_minmax(int *arr, int len, int num)
{
	if (ft_is_max(arr, len, num) || ft_is_min(arr, len, num))
		return (1);
	return (0);
}

int		ft_abs(int num_a, int num_b)
{
	int ans;

	if (num_a < 0)
		num_a *= -1;
	if (num_b < 0)
		num_b *= -1;
	if (num_a > num_b)
		ans = num_a - num_b;
	else
		ans = num_b - num_a;
	return (ans);
}
