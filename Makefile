# compile:
# 	cc -I /usr/local/include main.c -L /usr/local/bin/  -lmlx -framework OpenGL -framework AppKit && ./a.out

CC = cc
CFLAGS =

SRC = main.c window.c Get-Next-Line/get_next_line.c Get-Next-Line/get_next_line_utils.c \
		map/map_generator.c map/map_checker.c 
OBJ = $(SRC:.c=.o)
NAME = so_long.a

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)
	cc -I /usr/local/include main.c -L /usr/local/bin/  -lmlx -framework OpenGL -framework AppKit so_long.a libft/libft.a && ./a.out

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
	$(MAKE) -C libft

clean:
	rm -f $(OBJ)
	$(MAKE) -C libft clean

fclean: clean
	rm -f $(NAME)
	$(MAKE) -C libft fclean

re: fclean all

.PHONY: all bonus clean fclean re