# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: revieira <revieira@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/14 15:55:43 by revieira          #+#    #+#              #
#    Updated: 2022/10/18 13:57:09 by revieira         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= libftprintf.a
INCLUDES	= ./includes
PATH_SRC	= ./srcs/
SRCS 		= $(addprefix $(PATH_SRC),ft_printf.c ft_printf_utils.c)
OBJS 		= ft_printf.o ft_printf_utils.o
CFLAGS 		= cc -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	ar rcs $(NAME) $(OBJS)

%.o : $(PATH_SRC)%.c
	$(CFLAGS) -I $(INCLUDES) -c $< -o $@

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
