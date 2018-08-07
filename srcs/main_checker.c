/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:52:58 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/07 18:53:01 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		ft_is_viz(char **argv)
{
	if (ft_ccmd(argv[1]) == 2)
		return (1);
	if (ft_ccmd(argv[1]) == 3)
		return (2);
	return (0);
}

int		main(int argc, char **argv)
{
	t_stacks	*s;
	int			pflag;

	if (argc > 1)
	{
		s = init_struct();
		(pflag = ft_is_viz(argv)) && argv++;
		s->size = ft_count_args(argv);
		s->stack_a = (int *)malloc(sizeof(int) * s->size);
		s->stack_b = (int *)malloc(sizeof(int) * s->size);
		s->len_a = s->size;
		if (ft_is_error(argv) || !ft_store_arr(s, argv) || ft_is_dup(s)
				|| !ft_read(s, pflag))
		{
			write(1, "Error\n", 6);
			ft_free(s);
			return (0);
		}
		(ft_check_sorted(s) && s->len_b == 0) ? (write(1, "OK\n", 3)) :
			(write(1, "KO\n", 3));
		ft_free(s);
	}
	return (0);
}
