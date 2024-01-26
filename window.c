/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2024/01/26 17:41:58 by naadou           ###   ########.fr       */
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
		up(data, data->img_d.img, r, c);
		r -= 1;
	}
	if (move == 's')
	{
		if (data->map[r + 1][c] == '1')
			return ;
		down(data, data->img_d.img, r, c);
		r += 1;
	}
	if (move == 'd')
	{
		if (data->map[r][c + 1] == '1')
			return ;
		left(data, data->img_d.img, r, c);
		c += 1;
	}
	if (move == 'a')
	{
		if (data->map[r][c - 1] == '1')
			return ;
		right(data, data->img_d.img, r, c);
		c -= 1;
	}
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
