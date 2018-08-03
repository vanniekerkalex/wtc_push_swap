/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/30 15:11:27 by avan-ni           #+#    #+#             */
/*   Updated: 2018/08/03 17:47:56 by avan-ni          ###   ########.fr       */
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

void			ft_swap_a(t_stacks *s, int flag);
void			ft_swap_b(t_stacks *s, int flag);
void			ft_swap_ab(t_stacks *s, int flag);

void			ft_push_a(t_stacks *s, int flag);
void			ft_push_b(t_stacks *s, int flag);

void			ft_rotate_a(t_stacks *s, int flag);
void			ft_rotate_b(t_stacks *s, int flag);
void			ft_rotate_ab(t_stacks *s, int flag);

void			ft_rr_a(t_stacks *s, int flag);
void			ft_rr_b(t_stacks *s, int flag);
void			ft_rr_ab(t_stacks *s, int flag);

int				ft_ccmd(char *l);
void			ft_select_function(t_stacks *s, char *str);
int				ft_is_dup(t_stacks *s);

int				ft_count_args (char **argv);
int				ft_store_arr (t_stacks *s, char **argv);
int				ft_is_error(char **argv);
int				ft_read(t_stacks *s);
int				ft_check_sorted(t_stacks *s);

void			ft_print_arr(t_stacks *s);

int				ft_check_sorted_b(t_stacks *s);
int				ft_is_min(int *arr, int len, int num);
int				ft_is_max(int *arr, int len, int num);
int				ft_minmax(int *arr, int len, int num);
int				ft_abs(int num_a, int num_b);

int				ft_find_mm(int *arr, int len);
void			ft_sort(t_stacks *s, int l_b);
void			ft_sort_3(t_stacks *s, int l_b);
void			ft_sort_4(t_stacks *s);

void			ft_free(t_stacks *s);

#endif
