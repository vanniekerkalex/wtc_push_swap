/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-agr <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/04 16:51:01 by jde-agr           #+#    #+#             */
/*   Updated: 2018/08/04 17:13:47 by jde-agr          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_args(char **argv)
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

int	ft_store_arr(t_stacks *s, char **argv)
{
	char	**tmp;
	int		i;
	int		j;
	int		k;

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
			ft_strdel(&tmp[j++]);
			k++;
		}
		free(tmp);
		tmp = NULL;
		i++;
	}
	return (1);
}

int	ft_is_error(char **argv)
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

int	ft_read(t_stacks *s)
{
	char *line;

	while (get_next_line(0, &line))
	{
		if (ft_ccmd(line))
			ft_select_function(s, line);
		else
		{
			free(line);
			return (0);
		}
		free(line);
	}
	free(line);
	return (1);
}

int	ft_check_sorted(t_stacks *s)
{
	int i;

	i = 0;
	while (i < s->len_a - 1)
	{
		if (s->stack_a[i + 1] > s->stack_a[i])
			return (0);
		i++;
	}
	return (1);
}
