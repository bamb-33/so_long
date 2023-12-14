/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2023/12/14 15:35:12 by naadou           ###   ########.fr       */
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
	return (count * 100);
}

int	maps_width(char *map)
{
	int	i;

	i = 1;
	while (map[i] != '\n')
		i++;
	return (i * 50);
}
int	close_window(int keycode, t_args *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
	}
	return (0);
}

// void	my_mlx_pixel_put(t_args *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->img_data->addr + (y * data->img_data->line_length + x * (data->img_data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

void	window_creation(char *map, t_args data)
{
	int	w;
	int	h;

	w = maps_width(map);
	h = maps_height(map);
	data.mlx_window = mlx_new_window(data.mlx, w, h, "so_long");
	map_generator(map);
	data.img_data.img = mlx_xpm_file_to_image(data.mlx, "game_map.xpm", &w, &h);
	mlx_put_image_to_window(data.mlx, data.mlx_window, data.img_data.img, w, h);
	// data.img_data.addr = mlx_get_data_addr(data.img_data.img, &data.img_data.bits_per_pixel, 
	// 										&data.data_img.line_length, &data.img_data.endian);
	// mlx_put_image_to_window(void *window_ptr, void *image_ptr, int x_position, int y_position);
										
	
	mlx_key_hook(data.mlx_window, close_window, &data);
	
	mlx_loop(data.mlx);
	// mlx_destroy_display(data.mlx); // this function is not included in the header file of ma school for somereason
	// free(data.mlx);
}