compile:
	cc -I /usr/local/include main.c -L /usr/local/bin/  -lmlx -framework OpenGL -framework AppKit && ./a.out