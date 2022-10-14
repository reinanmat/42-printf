NAME 		= libftprint.a

INCLUDES 	= ft_printf.h

SRCS 		= ft_printf.c \
			  ft_printf_utils.c

OBJS 		= ft_printf.o \
			  ft_printf_utils.o

CFLAGS 		= -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	ar rc $(NAME) $(OBJS)

$(OBJS) : $(SRCS)
	cc $(CFLAGS) -I $(INCLUDES) -c $(SRCS)

clean :
	rm -f $(OBJS)

fclean : clean
	rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
