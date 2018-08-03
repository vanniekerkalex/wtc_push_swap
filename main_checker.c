/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:19:25 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:47:59 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	ft_print_arr(t_stacks *s)
{
	int i;

	i = s->len_a - 1;
	printf("TOP\n---\n");
	while (i >= 0)
		printf("%d\n", s->stack_a[i--]);
}

int main(int argc, char **argv)
{
	t_stacks	*s;
	s = init_struct();

	if (argc > 1)
	{
		s->size = ft_count_args(argv);
		s->stack_a = (int *)malloc(sizeof(int) * s->size);
		s->stack_b = (int *)malloc(sizeof(int) * s->size);
		s->len_a = s->size;
		if (ft_is_error(argv) || !ft_store_arr(s, argv) || ft_is_dup(s) || !ft_read(s))
		{
			write(1,"Error\n", 6);
			ft_free(s);
			return (0);
		}
		if (ft_check_sorted(s) && s->len_b == 0)
			write(1,"OK\n", 3);
		else
			write(1,"KO\n", 3);
	//	ft_print_arr(s);
		ft_free(s);

	}
	return (0);
}
