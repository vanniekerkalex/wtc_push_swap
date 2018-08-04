/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/01 14:11:52 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/04 16:11:35 by avan-ni          ###   ########.fr       */
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
			ft_sort_v5(s);
		//ft_print_arr(s);
		ft_free(s);
		//while (1)
		//;
	}
	return (0);
}
