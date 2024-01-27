/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2024/01/27 20:54:18 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

int	*starting_position(char **map_arr)
{
	int	w;
	int	h;
	int	*arr;

	w = 0;
	arr = (int *) malloc (2 * sizeof(int));
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

int	enemy_cont(char **map)
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

int	get_index(char **map, int w, int h)
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
			if (map[i][j] == 'G')
				count++;
			j++;
		}
		i++;
	}
	return (0);
}

void	enemy_sprites(void ***img, t_data *d, int w, int h)
{
	static int	*i;
	static int	*j;
	static int	*right;
	static int	*left;
	int			p;

	p = 0;
	if (!i && !j)
	{
		i = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		j = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		right = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		left = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		while (p < enemy_cont(d->map))
		{
			i[p] = 0;
			j[p] = 0;
			right[p] = 1;
			p++;
		}
	}
	p = get_index(d->map, w / 64, h / 64);
	if ((d->map[h / 64][(w / 64) + 1] == '1' || d->map[h / 64][(w / 64) + 1] == 'C' || d->map[h / 64][(w / 64) + 1] == 'G') && (d->map[h / 64][(w / 64) - 1] == '1' || d->map[h / 64][(w / 64) - 1] == 'C' || d->map[h / 64][(w / 64) - 1] == 'G'))
	{
		left[p] = 0;
		right[p] = 0;
	}
	else if (d->map[h / 64][(w / 64) + 1] == '1' || d->map[h / 64][(w / 64) + 1] == 'C' || d->map[h / 64][(w / 64) + 1] == 'G')
	{
		left[p] = 1;
		right[p] = 0;
	}
	else if (d->map[h / 64][(w / 64) - 1] == '1' || d->map[h / 64][(w / 64) - 1] == 'C' || d->map[h / 64][(w / 64) - 1] == 'G')
	{
		left[p] = 0;
		right[p] = 1;
	}
	if (i[p] == 100)
	{
		if (right[p] == 1)
		{
			d->map[h / 64][(w / 64)] = '0';
			d->map[h / 64][(w / 64) + 1] = 'G';
		}
		else if (left[p] == 1)
		{
			d->map[h / 64][(w / 64)] = '0';
			d->map[h / 64][(w / 64) - 1] = 'G';
		}
		i[p] = 0;
	}
	if (j[p] >= 0 && j[p] < 50)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][0], w, h);
	if (j[p] >= 50 && j[p] < 100)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][1], w, h);
	if (j[p] >= 100 && j[p] < 150)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][2], w, h);
	if (j[p] >= 150 && j[p] < 200)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][3], w, h);
	if (j[p] >= 200 && j[p] < 250)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][4], w, h);
	if (j[p] >= 250 && j[p] < 300)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][5], w, h);
	if (j[p] >= 300 && j[p] <= 350)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][6], w, h);
	if (j[p] == 350)
		j[p] = -1;
	i[p]++;
	j[p]++;
}

int	pixels(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	mlx_clear_window(data->mlx, data->mlx_window);
	while (data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == '0')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[0][0], j * 64, i * 64);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[1][0], j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[2][0], j * 64, i * 64);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[3][0], j * 64, i * 64);
			else if (data->map[i][j] == 'P')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[4][0], j * 64, i * 64);
			else if (data->map[i][j] == 'G')
				enemy_sprites(data->img_d.img, data, j * 64, i * 64);
			j++;
		}
		i++;
	}
	return (0);
}
