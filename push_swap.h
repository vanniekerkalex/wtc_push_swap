/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:11:27 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/01 17:43:22 by avan-ni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct	s_stacks
{
	int *stack_a;
	int *stack_b;
	int size;
	int len_a;
	int len_b;
	char *commands;
}				t_stacks;

t_stacks		*init_struct(void);

void			ft_swap_a(t_stacks *s);
void			ft_swap_b(t_stacks *s);
void			ft_swap_ab(t_stacks *s);

void			ft_push_a(t_stacks *s);
void			ft_push_b(t_stacks *s);

void			ft_rotate_a(t_stacks *s);
void			ft_rotate_b(t_stacks *s);
void			ft_rotate_ab(t_stacks *s);

void			ft_rr_a(t_stacks *s);
void			ft_rr_b(t_stacks *s);
void			ft_rr_ab(t_stacks *s);

int				ft_ccmd(char *l);
void			ft_select_function(t_stacks *s, char *str);
int				ft_is_dup (t_stacks *s);

int				ft_count_args (char **argv);
int				ft_store_arr (t_stacks *s, char **argv);
int				ft_is_error(char **argv);
int				ft_read(t_stacks *s);
int				ft_check_sorted(t_stacks *s);

void			ft_print_arr(t_stacks *s);

int				ft_check_sorted_b(t_stacks *s);


#endif
