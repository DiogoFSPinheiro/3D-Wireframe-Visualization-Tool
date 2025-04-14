CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = ft_printf.a

SRCS = ft_putchar_fd.c ft_putnbr_fd.c ft_putnbr_hexa.c \
ft_putstr_fd.c ft_printf.c ft_putnbr_fd_u.c ft_strlen.c \
ft_putnbr_ptr.c
#BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)
#BONUS_OBJS = $(BONUS_SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

#bonus: $(BONUS_OBJS) $(OBJS)
#	ar rc $(NAME) $(BONUS_OBJS) $(OBJS)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all 

.phony: all bonus clean fclean re 
