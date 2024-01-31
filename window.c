/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 11:15:46 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	maps_height(char **map)
{
	int	i;
	int	count;

	i = 1;
	count = 1;
	while (map[i])
	{
		i++;
	}
	return (i);
}

int	maps_width(char **map)
{
	int	i;

	i = 1;
	while (map[0][i])
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
		free_all(data, 5);
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

void	window_creation(t_data data)
{
	int	w;
	int	h;

	w = maps_width(data.map);
	h = maps_height(data.map);
	data.mlx_window = mlx_new_window(data.mlx, (w * 64), (h * 64), "so_long");
	mlx_loop_hook(data.mlx, pixels, &data);
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_loop(data.mlx);
}
