/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 15:08:38 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/07 18:29:12 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_choose(t_stacks *s, int p_flag)
{
	if (s->len_a == 3)
		ft_sort_3(s, 0, p_flag);
	else if (s->len_a == 4)
		ft_sort_4(s, p_flag);
	else if (s->len_a < 11)
		ft_sort(s, 0, p_flag);
	else
		ft_sort_v5(s, p_flag);
}

int		ft_is_viz2(char **argv)
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
		(pflag = ft_is_viz2(argv)) && argv++;
		s->size = ft_count_args(argv);
		s->stack_a = (int *)malloc(sizeof(int) * s->size);
		s->stack_b = (int *)malloc(sizeof(int) * s->size);
		s->len_a = s->size;
		if (ft_is_error(argv) || !ft_store_arr(s, argv) || ft_is_dup(s))
		{
			write(1, "Error\n", 6);
			ft_free(s);
			return (0);
		}
		ft_choose(s, pflag);
		ft_free(s);
	}
	return (0);
}
