/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 14:28:50 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	*starting_position(char **map_arr)
{
	int			w;
	int			h;
	static int	arr[2];

	w = 0;
	while (map_arr[w])
	{
		h = 0;
		while (map_arr[w][h])
		{
			if (map_arr[w][h] == 'P')
			{
				arr[0] = w;
				arr[1] = h;
				return (arr);
			}
			h++;
		}
		w++;
	}
	return (0);
}

int	enemy_count(char **map)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G')
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	get_enemy_index(char **map, int w, int h)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	count = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (i == h && j == w)
				return (count);
			if (map[i][j] == 'G' || map[i][j] == 'J')
				count++;
			j++;
		}
		i++;
	}
	return (0);
}

void	put_in_window(char c, t_data *d, int w, int h)
{
	void	***img;

	img = d->img;
	if (c == '0' || c == 'J')
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[0][0], w, h);
	else if (c == '1')
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[1][0], w, h);
	else if (c == 'C')
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[2][0], w, h);
	else if (c == 'E')
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[3][0], w, h);
	else if (c == 'P')
	{
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[0][0], w, h);
		player_sprites(img, d, w, h);
	}
	else if (c == 'G')
		enemy_sprites(img, d, w, h);
}

int	pixels(t_data *d)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	mlx_clear_window(d->mlx, d->mlx_window);
	collectibles_check(d);
	str = ft_itoa(d->mov_counter);
	while (d->map[i])
	{
		j = 0;
		while (d->map[i][j])
		{
			put_in_window(d->map[i][j], d, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_string_put(d->mlx, d->mlx_window, 0, 0, 16776960, str);
	free(str);
	return (0);
}
