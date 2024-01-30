/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2024/01/30 17:44:08 by naadou           ###   ########.fr       */
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

void	direction_movement(char move, t_data *data)
{
	if (move == 'w')
		up(data);
	if (move == 's')
		down(data);
	if (move == 'd')
		right(data);
	if (move == 'a')
		left(data);
	if (move == 'A')
		data->player_status = -1;
}

int	key_hook(int keycode, t_data *data)
{
	if (keycode == 53)
	{
		mlx_destroy_window(data->mlx, data->mlx_window);
		exit (0);
	}
	if (keycode == 126)
		direction_movement('w', data);
	if (keycode == 125)
		direction_movement('s', data);
	if (keycode == 124)
		direction_movement('d', data);
	if (keycode == 123)
		direction_movement('a', data);
	if (keycode == 49)
		direction_movement('A', data);
	return (0);
}

void	window_creation(char *map, t_data data)
{
	int	w;
	int	h;

	w = maps_width(map);
	h = maps_height(map);
	free(map);
	data.mlx_window = mlx_new_window(data.mlx, (w * 64), (h * 64), "so_long");
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_loop_hook(data.mlx, pixels, &data);
	mlx_loop(data.mlx);
}
