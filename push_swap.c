/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:11:52 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/02 19:42:52 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_arr(t_stacks *s)
{
	int i;

	i = s->len_a - 1;
	printf("\nTOP\n---\n");
	while (i >= 0)
		printf("%d\n", s->stack_a[i--]);
	printf("---\n\n");
}

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
	while (i < len - 1)
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
	while (i < len - 1)
	{
		if (num < arr[i])
			return (0);
		i++;
	}
	return (1);
}


void	ft_sort(t_stacks *s)
{
	int i;

	i = 0;
	if (!ft_check_sorted(s) || s->len_b > 0)
	{
		while (!ft_check_sorted(s) || s->len_b > 0)
		{
			if (ft_is_min(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
				ft_push_b(s);
			else if (ft_is_max(s->stack_a, s->len_a, s->stack_a[s->len_a - 1]))
				ft_rr_a(s);
			else if (s->stack_a[s->len_a - 1] > s->stack_a[s->len_a - 2])
				ft_swap_a(s);
			else
				ft_rr_a(s);
			while (ft_check_sorted(s) && s->len_b > 0)
			{
				ft_push_a(s);
				i++;
			}
			i++;
		}
	}
	printf("\nCycles: %d\n", i);
}

int main (int argc, char **argv)
{
	t_stacks	*s;
	s = init_struct();

	if (argc > 1)
	{
		s->size = ft_count_args(argv);
		s->stack_a = (int *)malloc(sizeof(int) * s->size);
		s->stack_b = (int *)malloc(sizeof(int) * s->size);
		s->len_a = s->size;
		if (ft_is_error(argv) || !ft_store_arr(s, argv) || ft_is_dup(s))
		{
			write(1,"Error\n", 6);
			return (0);
		}
		ft_print_arr(s);
		ft_sort(s);
		ft_print_arr(s);
	}
	return (0);
}
