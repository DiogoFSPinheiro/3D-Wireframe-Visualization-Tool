CC = cc

CFLAGS = -Wall -Wextra -Werror

NAME = get_next_line.a

SRCS = get_next_line.c get_next_line_utils.c
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
