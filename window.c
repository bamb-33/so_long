/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2023/12/14 18:53:41 by naadou           ###   ########.fr       */
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

int	close_window(int keycode, t_args *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
	}
	return (0);
}

void	window_creation(char *map, t_args data)
{
	int	w;
	int	h;

	w = 1020;
	h = 720;
	data.mlx_window = mlx_new_window(data.mlx, w, h, "so_long");
	map_generator(map);
	// data.img_data.img = mlx_xpm_file_to_image(data.mlx, "game_map.xpm", &w, &h);
	// mlx_put_image_to_window(data.mlx, data.mlx_window, data.img_data.img, w, h);
	mlx_key_hook(data.mlx_window, close_window, &data);
	mlx_loop(data.mlx);
}
