/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2023/12/16 22:02:08 by naadou           ###   ########.fr       */
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

void	direction_movement(char c, t_args *data, int w, int h)
{
	static int	*c_position;

	if (c_position == NULL)
	{
		c_position = starting_position(data->map_arr);
	}
	if (c == 'w')
	{
		if (data->map_arr[(c_position[0] / 50) - 1][c_position[1] / 35] == '1')
			return ;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/dirt.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
		c_position[0] -= 50;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/eye_of_ender.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
	}
	if (c == 's')
	{
		if (data->map_arr[(c_position[0] / 50) + 1][c_position[1] / 35] == '1')
			return ;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/dirt.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
		c_position[0] += 50;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/eye_of_ender.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
	}
	if (c == 'd')
	{
		if (data->map_arr[c_position[0] / 50][(c_position[1] / 35) + 1] == '1')
			return ;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/dirt.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
		c_position[1] += 35;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/eye_of_ender.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
	}
	if (c == 'a')
	{
		if (data->map_arr[c_position[0] / 50][(c_position[1] / 35) - 1] == '1')
			return ;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/dirt.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
		c_position[1] -= 35;
		mlx_destroy_image(data->mlx, data->img_data.img[c_position[0] / 50][c_position[1] / 35]);
		data->img_data.img[c_position[0] / 50][c_position[1] / 35] = mlx_xpm_file_to_image(data->mlx, "map_blocs/eye_of_ender.xpm", &w, &h);
		mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_data.img[c_position[0] / 50][c_position[1] / 35], c_position[1], c_position[0]);
	}
	//mlx_string_put(data->mlx, data->mlx_window, 100, 100, 16773120, "ain't no way");
}

int	key_hook(int keycode, t_args *data)
{
	if (keycode == 53) //ESC
		mlx_destroy_window(data->mlx, data->mlx_window);
	if (keycode == 126) // up
		direction_movement('w', data, 35, 50);
	if (keycode == 125) // down
		direction_movement('s', data, 35, 50);
	if (keycode == 124) // right
		direction_movement('d', data, 35, 50);
	if (keycode == 123) // left
		direction_movement('a', data, 35, 50);
	return (0);
}

void	window_creation(char *map, t_args data)
{
	int	w;
	int	h;
	int	*starting_position;

	w = maps_width(map);
	h = maps_height(map);
	data.mlx_window = mlx_new_window(data.mlx, (w * 35), (h * 50), "so_long");
	pixels(map, data, 35, 50);
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_loop(data.mlx);
}
