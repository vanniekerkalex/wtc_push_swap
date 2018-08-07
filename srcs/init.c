/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/07 18:52:22 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/07 19:31:12 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stacks	*init_struct(void)
{
	t_stacks *s;

	s = (t_stacks *)malloc(sizeof(t_stacks));
	s->stack_a = NULL;
	s->stack_b = NULL;
	s->size = 0;
	s->len_a = 0;
	s->len_b = 0;
	return (s);
}

void		ft_viz_cool(t_stacks *s, int y, int x)
{
	int i;
	int j;

	i = 0;
	start_color();
	init_pair(1, COLOR_GREEN, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_WHITE, COLOR_BLACK);
	attron(COLOR_PAIR(3));
	mvprintw(y, x, "COOLEST VIZ IN THE WORLD\n");
	mvprintw(y + 1, x, "------------------------\n");
	attron(COLOR_PAIR(1));
	while (i <= s->len_a - 1)
	{
		j = 0;
		while (j <= (s->stack_a[s->len_a - i - 1] / 1))
			mvprintw(y + i + 2, x + j++, "X");
		i++;
	}
	attron(COLOR_PAIR(2));
	while (i <= s->size - 1)
	{
		j = 0;
		while (j <= (s->stack_b[s->size - i - 1] / 1))
			mvprintw(y + i + 1, x + j++, "X");
		i++;
	}
}
