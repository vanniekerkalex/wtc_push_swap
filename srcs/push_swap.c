/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:55:36 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/04 17:13:31 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
		if (s->len_a == 3)
			ft_sort_3(s, 0);
		else if (s->len_a == 4)
			ft_sort_4(s);
		else if (s->len_a < 11)
			ft_sort(s, 0);
		else
			ft_sort_v5(s);
		ft_free(s);
	}
	return (0);
}
