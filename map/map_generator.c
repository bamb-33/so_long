/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 14:29:33 by naadou            #+#    #+#             */
/*   Updated: 2024/01/28 14:46:03 by naadou           ###   ########.fr       */
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
			if (map[i][j] == 'G' || map[i][j] == 'J')
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
	static int	*k;
	static int	*right;
	static int	*left;
	int			p;

	p = 0;
	if (!i && !j)
	{
		i = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		j = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		k = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		right = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		left = (int *) malloc (sizeof(int) * enemy_cont(d->map));
		while (p < enemy_cont(d->map))
		{
			i[p] = 0;
			j[p] = 0;
			k[p] = 0;
			right[p] = 1;
			p++;
		}
	}
	p = get_index(d->map, w / 64, h / 64);
	if (d->enemy_status[p] == -1)
	{
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[0][0], w, h);
		if (k[p] >= 0 && k[p] < 10)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][7], w, h);
		if (k[p] >= 10 && k[p] < 20)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][8], w, h);
		if (k[p] >= 20 && k[p] < 30)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][9], w, h);
		if (k[p] >= 30 && k[p] < 40)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][10], w, h);
		if (k[p] >= 40 && k[p] < 50)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][11], w, h);
		if (k[p] >= 50 && k[p] < 60)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][12], w, h);
		if (k[p] >= 60 && k[p] <= 70)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][13], w, h);
		if (k[p] == 70)
		{
			d->map[h / 64][(w / 64)] = 'J';
			d->enemy_status[p] = 1;
			k[p] = -1;
		}
		k[p]++;
		return ;
	}
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
			if (d->map[h / 64][(w / 64) + 1] == 'P')
			{
				printf("YOU DIED LIL NIGGA\n");
				exit(0);
			}
			d->map[h / 64][(w / 64)] = '0';
			d->map[h / 64][(w / 64) + 1] = 'G';
		}
		else if (left[p] == 1)
		{
			if (d->map[h / 64][(w / 64) - 1] == 'P')
			{
				printf("YOU DIED LIL NIGGA\n");
				exit(0);
			}
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

void	player_sprites(void ***img, t_data *d, int w, int h)
{
	static int	i;
	static int	j;
	int			*p;

	p = starting_position(d->map);
	if (d->player_status == -1)
	{
		if (d->map[p[0]][p[1] + 1] == 'G')
			d->enemy_status[get_index(d->map, p[1] + 1, p[0])] = -1;
		if (d->map[p[0]][p[1] - 1] == 'G')
			d->enemy_status[get_index(d->map, p[1] - 1, p[0])] = -1;
		if (j >= 0 && j < 10)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][8], w, h);
		if (j >= 10 && j < 20)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][9], w, h);
		if (j >= 20 && j < 30)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][10], w, h);
		if (j >= 30 && j < 40)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][11], w, h);
		if (j >= 40 && j < 50)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][12], w, h);
		if (j >= 50 && j < 60)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][13], w, h);
		if (j >= 60 && j <= 70)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][14], w, h);
		if (j >= 70 && j <= 80)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][15], w, h);
		if (j >= 80 && j <= 90)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][16], w, h);
		if (j >= 90 && j <= 100)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][17], w, h);
		if (j >= 100 && j <= 110)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][18], w, h);
		if (j >= 110 && j <= 120)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][19], w, h);
		if (j >= 120 && j <= 130)
			mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][20], w, h);
		if (j == 130)
		{
			d->player_status = 1;
			j = -1;
			i = 0;
		}
		j++;
		return ;
	}
	if (i >= 0 && i < 50)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][0], w, h);
	if (i >= 50 && i < 100)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][1], w, h);
	if (i >= 100 && i < 150)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][2], w, h);
	if (i >= 150 && i < 200)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][3], w, h);
	if (i >= 200 && i < 250)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][4], w, h);
	if (i >= 250 && i < 300)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][5], w, h);
	if (i >= 300 && i <= 350)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][6], w, h);
	if (i >= 350 && i <= 400)
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][7], w, h);
	if (i == 400)
		i = -1;
	i++;
}

int	pixels(t_data *data)
{
	int		i;
	int		j;
	char	*str;
	int		w;
	int		h;

	i = 0;
	j = 0;
	w = 64;
	h = 64;
	mlx_clear_window(data->mlx, data->mlx_window);
	str = ft_itoa(data->mov_counter);
	if (collectibles_check(data->map) == 1)
		data->img_d.img[3][0] = mlx_xpm_file_to_image(data->mlx, "blocs/E1.xpm",&w , &h);
	while (data->map[i])
	{
		j = 0;
		while(data->map[i][j])
		{
			if (data->map[i][j] == '0' || data->map[i][j] == 'J')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[0][0], j * 64, i * 64);
			else if (data->map[i][j] == '1')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[1][0], j * 64, i * 64);
			else if (data->map[i][j] == 'C')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[2][0], j * 64, i * 64);
			else if (data->map[i][j] == 'E')
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[3][0], j * 64, i * 64);
			else if (data->map[i][j] == 'P')
			{
				mlx_put_image_to_window(data->mlx, data->mlx_window, data->img_d.img[0][0], j * 64, i * 64);
				player_sprites(data->img_d.img, data, j * 64, i * 64);
			}
			else if (data->map[i][j] == 'G')
				enemy_sprites(data->img_d.img, data, j * 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_string_put(data->mlx, data->mlx_window, 0, 0, 16776960, str);
	free(str);
	return (0);
}
