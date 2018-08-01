/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:15:25 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/01 16:29:49 by avan-ni          ###   ########.fr       */
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
	s->commands = NULL;
	return (s);
}
