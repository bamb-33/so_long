/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 13:04:50 by naadou            #+#    #+#             */
/*   Updated: 2024/01/27 22:21:22 by naadou           ###   ########.fr       */
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
	int w = 64;
	int h = 64;
	// char		*str;
	// static int	i;

	p = starting_position(data->map);
	if (collectibles_check(data->map) == 1)
	{
		data->img_d.img[3][0] = mlx_xpm_file_to_image(data->mlx, "blocs/E1.xpm",&w , &h);
	}
	if (move == 'w')
	{
		if (data->map[p[0] - 1][p[1]] == 'E' && collectibles_check(data->map) == 1)
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		if (data->map[p[0] - 1][p[1]] == 'G')
			exit(0);
		if (data->map[p[0] - 1][p[1]] == '1' || data->map[p[0] - 1][p[1]] == 'E')
			return ;
		data->map[p[0] - 1][p[1]] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	if (move == 's')
	{
		if (data->map[p[0] + 1][p[1]] == 'E' && collectibles_check(data->map) == 1)
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		if (data->map[p[0] + 1][p[1]] == 'G')
			exit(0);
		if (data->map[p[0] + 1][p[1]] == '1' || data->map[p[0] + 1][p[1]] == 'E')
			return ;
		data->map[p[0] + 1][p[1]] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	if (move == 'd')
	{
		if (data->map[p[0]][p[1] + 1] == 'E' && collectibles_check(data->map) == 1)
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		if (data->map[p[0]][p[1] + 1] == 'G')
			exit(0);
		if (data->map[p[0]][p[1] + 1] == '1' || data->map[p[0]][p[1] + 1] == 'E')
			return ;
		data->map[p[0]][p[1] + 1] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	if (move == 'a')
	{
		if (data->map[p[0]][p[1] - 1] == 'E' && collectibles_check(data->map) == 1)
		{
			printf("YOU WON!!!!");
			exit(0);
		}
		if (data->map[p[0]][p[1] - 1] == 'G')
			exit(0);
		if (data->map[p[0]][p[1] - 1] == '1' || data->map[p[0]][p[1] - 1] == 'E')
			return ;
		data->map[p[0]][p[1] - 1] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	// i++;
	// str = ft_itoa(i);
	// mlx_string_put(data->mlx, data->mlx_window, 0, 0, 16776960, str);
	// free(str);
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
	mlx_key_hook(data.mlx_window, key_hook, &data);
	mlx_loop_hook(data.mlx, pixels, &data);
	mlx_loop(data.mlx);
}
