/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:19:25 by avan-ni           #+#    #+#             */
/*   Updated: 2018/07/31 17:28:57 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

int		ft_count_args (char **argv)
{
	int count;
	int i;

	i = 1;
	count = 0;
	while (argv[i])
	{
		count += ft_wcount(argv[i], ' ');
		i++;
	}
	return (count);
}

int		ft_store_arr (t_stacks *s, char **argv)
{
	char **tmp;
	int i;
	int j;
	int k;

	i = 1;
	k = 0;
	while (argv[i])
	{
		j = 0;
		tmp = ft_strsplit(argv[i], ' ');
		while (tmp[j])
		{
			s->stack_a[s->size - 1 - k] = ft_atoi(tmp[j]);
			if (((tmp[j][0] != '0') && ft_strcmp(tmp[j], "-0"))
					&& s->stack_a[s->size - 1 - k] == 0)
				return (0);
			j++;
			k++;
		}
		ft_strdel(tmp);
		i++;
	}
	return (1);
}

int		ft_is_error(char **argv)
{
	int i;
	int j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!(ft_isdigit(argv[i][j])) && (argv[i][j] != ' ')
					&& argv[i][j] != '+' && argv[i][j] != '-')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_print_arr(t_stacks *s)
{
	int i;

	i = s->len_a - 1;
	printf("TOP\n---\n");
	while (i >= 0)
		printf("%d\n", s->stack_a[i--]);
}

int	ft_ccmd(char *l)
{
	if (!ft_strcmp(l, "sa") || !ft_strcmp(l, "sb") ||
		!ft_strcmp(l, "ss") || !ft_strcmp(l, "pa") ||
		!ft_strcmp(l, "pb") || !ft_strcmp(l, "ra") ||
		!ft_strcmp(l, "rb") || !ft_strcmp(l, "rr") ||
		!ft_strcmp(l, "rra") || !ft_strcmp(l, "rrb") ||
		!ft_strcmp(l, "rrr"))
		return (1);
	return (0);
}

void	ft_select_function(t_stacks *s, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_swap_a(s);
	else if (ft_strcmp(str, "sb") == 0)
		ft_swap_b(s);
	else if (ft_strcmp(str, "ss") == 0)
		ft_swap_ab(s);
	else if (ft_strcmp(str, "pa") == 0)
		ft_push_a(s);
	else if (ft_strcmp(str, "pb") == 0)
		ft_push_b(s);
	else if (ft_strcmp(str, "ra") == 0)
		ft_rotate_a(s);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rotate_b(s);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rotate_ab(s);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rr_a(s);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rr_b(s);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rr_ab(s);
}

int		ft_read(t_stacks *s)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_ccmd(line))
			ft_select_function(s, line);
		else
		{
			ft_strdel(&line);
			return (0);
		}
		ft_strdel(&line);
	}
	return (1);
}

int		ft_check_sorted(t_stacks *s)
{
	int i;

	i = 0;
	while (i < s->len_a - 1)
	{
		if (s->stack_a[i + 1] >= s->stack_a[i])
			return (0);
		i++;
	}
	return (1);
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
		if (ft_is_error(argv) || !ft_store_arr(s, argv) || !ft_read(s))
		{
			write(1,"Error\n", 6);
			return (0);
		}
		if (ft_check_sorted(s))
			write(1,"OK\n", 3);
		else
			write(1,"KO\n", 3);
		ft_print_arr(s);
	}
	return (0);
}
