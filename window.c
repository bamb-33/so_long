/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2024/01/21 20:25:42 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	maps_height(char *map)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	while (map[i])
	{
		if (map[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int	maps_width(char *map)
{
	int	i;

	i = 1;
	while (map[i] != '\n')
		i++;
	return (i);
}

void	direction_movement(char move, t_data *data, int w, int h)
{
	int			*p;
	static int	r;
	static int	c;

	if (!r && !c)
	{
		p = starting_position(data->map);
		r = p[0];
		c = p[1];
	}
	if (move == 'w')
	{
		if (data->map[r - 1][c] == '1')
			return ;
		if (data->map[r - 1][c] == 'C')
			data->map[r - 1][c] = '0';
		if (data->map[r - 1][c] == 'E' && collectibles_check(data->map))
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
		r -= 1;
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
	}
	if (move == 's')
	{
		if (data->map[r + 1][c] == '1')
			return ;
		if (data->map[r + 1][c] == 'C')
			data->map[r + 1][c] = '0';
		if (data->map[r + 1][c] == 'E' && collectibles_check(data->map))
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
		r += 1;
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
	}
	if (move == 'd')
	{
		if (data->map[r][c + 1] == '1')
			return ;
		if (data->map[r][c + 1] == 'C')
			data->map[r][c + 1] = '0';
		if (data->map[r][c + 1] == 'E' && collectibles_check(data->map))
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
		c += 1;
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
	}
	if (move == 'a')
	{
		if (data->map[r][c - 1] == '1')
			return ;
		if (data->map[r][c - 1] == 'C')
			data->map[r][c - 1] = '0';
		if (data->map[r][c - 1] == 'E' && collectibles_check(data->map))
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
		c -= 1;
		mlx_destroy_image(data->mlx, data->img_d.img[r][c]);
		data->img_d.img[r][c] = mlx_xpm_file_to_image(data->mlx, "blocs/P.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[r][c], c * 64, r * 64);
	}
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53) //ESC
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		exit (0);
	}
	if (keycode == 126) // up
		direction_movement('w', data, 64, 64);
	if (keycode == 125) // down
		direction_movement('s', data, 64, 64);
	if (keycode == 124) // right
		direction_movement('d', data, 64, 64);
	if (keycode == 123) // left
		direction_movement('a', data, 64, 64);
	return (0);
}

void	window_creation(char *map, t_data data)
{
	int	w;
	int	h;

	w = maps_width(map);
	h = maps_height(map);
	data.mlx_window = mlx_new_window(data.mlx, (w * 64), (h * 64), "so_long");
	pixels(map, data, 64, 64);
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_loop(data.mlx);
}
