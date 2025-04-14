MAKEFLAGS += -s

CC = cc -g 

CFLAGS = -Wall -Wextra -Werror 

MINILXFLAGS = -L ./minilibx-linux -lmlx -Ilmlx -lXext -lX11 -lbsd -no-pie -lm

NAME = fdf

SRCS = main.c data_parsing.c render.c utils.c events.c img_create.c utils2.c

LIBFT = ./libraries/libft/libft.a
PRINTF = ./libraries/printf/ft_printf.a
#GET_NEXT_LINE = ./libraries/get_next_line/get_next_line.a
LIBX = ./minilibx-linux/libmlx_Linux.a

GREEN		= \033[38;5;47m
YELLOW		= \033[38;5;226m
RED		= \033[38;5;196m
RESET 		= \033[0m

#BONUS_SRCS = 

OBJS = $(SRCS:.c=.o)

#$(GET_NEXT_LINE)
all: $(LIBFT) $(PRINTF)  $(LIBX) $(NAME) 

$(NAME): $(LIBFT) $(PRINTF)  $(LIBX) $(OBJS) 
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(PRINTF) $(LIBX) $(MINILXFLAGS)  -o $(NAME)
	@echo "$(GREEN)Executable $(NAME) created"
	@echo " /###### /##          /##       /##                               /##"
	@echo "|_  ##_/| ##          | ##      |__/                              | ##"
	@echo "  | ## /######        | ##       /## /##    /## /######   /#######| ##"
	@echo "  | ##|_  ##_/        | ##      | ##|  ##  /##//##__  ## /##_____/| ##"
	@echo "  | ##  | ##          | ##      | ## \  ##/##/| ########|  ###### |__"
	@echo "  | ##  | ## /##      | ##      | ##  \  ###/ | ##_____/ \____ ##"
	@echo "/######|  ####/       | ########| ##   \  #/  |  ####### /######/ /##"
	@echo "|______/ \___/        |________/|__/    \_/    \_______/|_______/ |__"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡶⢿⣿⣿⢿⣿⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣉⠁⢈⣉⠁⠈⠛⠃⠘⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣦⣾⣿⡇⣼⣿⣧⣰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿ o ⣿⣿⣿ o ⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀  "
	@echo "⠀⠀⠀⠀⠀⢠⡄⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣤⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢸⡷⠶⠦⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠴⠶⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠘⠃⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣿⠟⢀⠀⠀⠀⠛⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣠⡀⠺⣿⣷⣦⣉⠛⠛⠛⠋⣡⣴⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⠟⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣾⣿⣿⣿⣿⣷⠄⠀⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⣿⣯⣶⣶⡀⠉⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠛⢻⣿⣿⣥⣤⡈⠻⠛⣻⣿⣿⡟⠛⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣏⣠⡀⢿⣿⣿⡇⠀⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠉⠉⠉⠉⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠁⠀⠉⠉⠉⠉⠀⠀⠀⠀$(RESET)"

#bonus: $(BONUS_OBJS) $(OBJS)
#	ar rc $(NAME) $(BONUS_OBJS) $(OBJS)  mete no clean -> $(BONUS_OBJS)

clean:
	rm -rf $(OBJS) 
	@echo "$(YELLOW)Removing $(NAME) objects files$(RESET)" 
	cd libraries && cd libft && make clean
	cd libraries && cd printf && make clean
	cd minilibx-linux && make clean

fclean: clean
	rm -rf $(NAME) 
	@echo "$(RED)Removing $(NAME) executable"
	@echo " /###### /##          /#######  /##                 /##"
	@echo "|_  ##_/| ##         | ##__  ##|__/                | ##"
	@echo "  | ## /######       | ##  \ ## /##  /######   /#######"
	@echo "  | ##|_  ##_/       | ##  | ##| ## /##__  ## /##__  ##"
	@echo "  | ##  | ##         | ##  | ##| ##| ########| ##  | ##"
	@echo "  | ##  | ## /##     | ##  | ##| ##| ##_____/| ##  | ##"
	@echo " /######  ####/      | #######/| ##|  #######|  #######"
	@echo "|______/ \___/       |_______/ |__/ \_______/ \_______/"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣀⣤⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡶⢿⣿⣿⢿⣿⡿⣦⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣉⠁⢈⣉⠁⠈⠛⠃⠘⠓⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣾⣿⣦⣾⣿⡇⣼⣿⣧⣰⣿⡇⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⠀⠀⠀⣿⣿ x ⣿⣿⣿ x ⣿⠀⠀⠀⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢠⡄⠀⠀⢿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀⣤⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⢸⡷⠶⠦⠘⢿⣿⣿⣿⣿⣿⣿⣿⣿⡿⠁⠴⠶⣿⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠘⠃⠀⠀⠀⠈⢻⣿⣿⣿⣿⣿⣿⠟⢀⠀⠀⠀⠛⠀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠀⠀⣠⡀⠺⣿⣷⣦⣉⠛⠛⠛⠋⣡⣴⣿⣿⣿⣶⣤⡀⠀⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⢀⣾⣿⠟⠀⠀⢰⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡄⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣾⣿⣿⣿⣿⣷⠄⠀⢼⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⣿⣯⣶⣶⡀⠉⢡⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠛⢻⣿⣿⣥⣤⡈⠻⠛⣻⣿⣿⡟⠛⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⣿⣿⣿⣿⠀⢸⣿⣿⣿⣿⣏⣠⡀⢿⣿⣿⡇⠀⣿⣿⣿⣿⠀⠀⠀⠀"
	@echo "⠀⠀⠀⠀⠉⠉⠉⠉⠀⠈⠉⠉⠉⠉⠉⠉⠉⠀⠉⠉⠁⠀⠉⠉⠉⠉⠀⠀⠀⠀$(RESET)"
	cd libraries && cd libft && make fclean
	cd libraries && cd printf && make fclean


re: fclean all 

.phony: all bonus clean fclean re 

################################# Making librarys #########################
$(LIBFT):
	cd libraries && cd libft && make 
	
$(PRINTF):
	cd libraries && cd printf && make 

#$(GET_NEXT_LINE):
#	cd libraries && cd get_next_line && make
	
$(LIBX):
	cd minilibx-linux && make
	
	 

