# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: avan-ni <avan-ni@student.wethinkcode.co.za>+#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/07/31 13:16:05 by avan-ni           #+#    #+#              #
#    Updated: 2018/07/31 13:16:30 by avan-ni          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CHECK = checker

FLAGS = -Wall -Werror -Wextra

SRCS = *.c

OBJS = *.o

HEADERS = -I libft/includes -I ./

LIB = libft/libft.a

$(CHECK) :
	make fclean -C libft/
	make -C libft/
	make clean -C libft/
	gcc $(FLAGS) -c $(SRCS) $(HEADERS)
	gcc $(FLAGS) $(OBJS) -o $(CHECK) $(LIB)
	make clean

all : $(CHECK)

clean :
	rm -rf $(OBJS)

fclean : clean
	make fclean -C libft/
	rm -rf $(CHECK)

re : fclean all
