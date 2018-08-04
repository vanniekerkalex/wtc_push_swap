/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:11:52 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/04 14:12:41 by jde-agr          ###   ########.fr       */
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

void	ft_sort_v3(t_stacks *s)
{
	int i;

	i = 0;
	if (!ft_check_sorted(s) || s->len_b > 0)
	{
		while (s->len_a > 0)
		{
			ft_push_b(s, 1);
			i++;
		}
		while (!ft_check_sorted(s) || s->len_b > 0)
		{
			if (ft_is_max(s->stack_b, s->len_b, s->stack_b[s->len_b - 1]))
				ft_push_a(s, 1);
			else if (ft_is_min(s->stack_b, s->len_b, s->stack_b[s->len_b - 1]))
			{
				ft_push_a(s, 1);
				ft_rotate_a(s, 1);
			}
			else if (ft_minmax(s->stack_b, s->len_b, s->stack_b[s->len_b - 2]))
				ft_swap_b(s, 1);
			else if (ft_minmax(s->stack_b, s->len_b, s->stack_b[0]))
				ft_rr_b(s, 1);
			else
				ft_rr_b(s, 1);
			i++;
			if (ft_check_sorted_b(s) && s->len_b > 0)
				while (s->len_b > 0)
				{
					ft_push_a(s, 1);
					i++;
				}
			while (s->len_b == 0 && !ft_check_sorted(s))
				ft_rotate_a(s, 1);
		}
	}
	//printf("\nCycles: %d\n", i);
}

void	ft_sort_v4(t_stacks *s)
{
	int i;

	i = 0;
	if (!ft_check_sorted(s) || s->len_b > 0)
	{
		while (s->len_a > 0)
		{
			ft_push_b(s, 1);
			i++;
		}
		while (!ft_check_sorted(s) || s->len_b > 0)
		{
			if (ft_is_max(s->stack_b, s->len_b, s->stack_b[s->len_b - 1]))
				ft_push_a(s, 1);
			else if (ft_is_min(s->stack_b, s->len_b, s->stack_b[s->len_b - 1]))
			{
				ft_push_a(s, 1);
				ft_rotate_a(s, 1);
			}
			else if (ft_find_mm(s->stack_b, s->len_b) == 2)
				ft_rotate_b(s, 1);
			else
				ft_rr_b(s, 1);
			i++;
			if (ft_check_sorted_b(s) && s->len_b > 0)
				while (s->len_b > 0)
				{
					ft_push_a(s, 1);
					i++;
				}
			while (s->len_b == 0 && !ft_check_sorted(s))
			{
				ft_rotate_a(s, 1);
				i++;
			}
		}
	}
	//printf("\nCycles: %d\n", i);
}

int		main(int argc, char **argv)
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
			write(1, "Error\n", 6);
			return (0);
		}
		//ft_print_arr(s);
		if (s->len_a == 3)
			ft_sort_3(s, 0);
		else if (s->len_a == 4)
			ft_sort_4(s);
		else if (s->len_a < 11)
			ft_sort(s, 0);
		else
			ft_sort_v4(s);
		//ft_print_arr(s);
		ft_free(s);
		//while (1)
		//;
	}
	return (0);
}
