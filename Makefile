# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-ni <avan-ni@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 13:16:05 by avan-ni           #+#    #+#              #
#    Updated: 2018/08/03 17:28:45 by avan-ni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker

PS = push_swap

FLAGS = -Wall -Werror -Wextra

SRCS = checker_functions.c checker_functions2.c checker_functions3.c init.c \
check_cmd.c check_args.c sorting_small.c sorting_big.c assist.c

OBJS = checker_functions.o checker_functions2.o checker_functions3.o init.o \
check_cmd.o check_args.o sorting_small.o sorting_big.o assist.o

HEADERS = -I libft/includes -I ./

LIB = libft/libft.a

$(CHECK) :
	@make fclean -C libft/
	@make -C libft/
	@make clean -C libft/
	gcc $(FLAGS) -c $(SRCS) main_checker.c $(HEADERS)
	gcc $(FLAGS) $(OBJS) main_checker.o -o $(CHECK) $(LIB)
	@make clean

$(PS) :
	@make fclean -C libft/
	@make -C libft/
	@make clean -C libft/
	gcc $(FLAGS) -c $(SRCS) push_swap.c $(HEADERS)
	gcc $(FLAGS) $(OBJS) push_swap.o -o $(PS) $(LIB)
	@make clean

all : $(CHECK) $(PS)

clean :
	@rm -rf $(OBJS) main_checker.o push_swap.o

fclean : clean
	@make fclean -C libft/
	@rm -rf $(CHECK) $(PS)

re : fclean all
