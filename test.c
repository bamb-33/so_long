#include <mlx.h>

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1080, "Hello world!");
	img.img = mlx_new_image(mlx, 1080, 1080);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
								&img.endian);
	for (int i = 1080 / 4; i < 1080 / 2; i++)
		my_mlx_pixel_put(&img, i + 0.1, i, 0x00FF0000);
	// for (int i = 1080 / 4; i < 1080 / 2; i++)
	// 	my_mlx_pixel_put(&img, i, 1080 / 4, 0x00FF0000);
	// for (int i = 1080 / 4; i < 1080 / 2; i++)
	// 	my_mlx_pixel_put(&img, 1080 / 2, i, 0x00FF0000);
	// for (int i = 1080 / 4; i < 1080 / 2; i++)
	// 	my_mlx_pixel_put(&img, i, 1080 / 2, 0x00FF0000);
	
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 210);
	mlx_loop(mlx);
}
















// #include <mlx.h>
// #include <stdio.h>

// typedef struct	s_vars {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// int	close(int keycode, t_vars *vars)
// {
// 	// printf ("%d\n", keycode);
// 	if (keycode == 53)
// 		mlx_destroy_window(vars->mlx, vars->win);
// 	return (0);
// }

// int	main(void)
// {
// 	t_vars	vars;

// 	vars.mlx = mlx_init();
// 	vars.win = mlx_new_window(vars.mlx, 500, 300, "Hello world!");
// 	mlx_key_hook(vars.win, &close, &vars);
// 	mlx_loop(vars.mlx);
// }