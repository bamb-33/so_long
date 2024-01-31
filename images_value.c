/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   images_value.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:28:24 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 14:29:36 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_previous(t_data *d, char *map, int flag)
{
	int	i;

	i = 0;
	free(map);
	if (flag >= 1)
		free_two_d_array(d->map);
	if (flag >= 2)
		free(d->enemy_status);
	if (flag >= 3)
	{
		if (!d->img)
		{
			free(d->img);
			exit(1);
		}
	}
	if (flag >= 4)
	{
		while (d->img[i])
			free(d->img[i++]);
	}
	exit(1);
}

void	init_basic_blocks(void ***img, t_data *data, int w, int h)
{
	img[0][0] = mlx_xpm_file_to_image(data->mlx, "blocs/0.xpm", &w, &h);
	img[1][0] = mlx_xpm_file_to_image(data->mlx, "blocs/1.xpm", &w, &h);
	img[2][0] = mlx_xpm_file_to_image(data->mlx, "blocs/C.xpm", &w, &h);
	img[3][0] = mlx_xpm_file_to_image(data->mlx, "blocs/E.xpm", &w, &h);
}

void	init_player_sprite_imgs(void ***img, t_data *data, int w, int h)
{
	img[4][0] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/1.xpm", &w, &h);
	img[4][1] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/2.xpm", &w, &h);
	img[4][2] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/3.xpm", &w, &h);
	img[4][3] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/4.xpm", &w, &h);
	img[4][4] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/5.xpm", &w, &h);
	img[4][5] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/6.xpm", &w, &h);
	img[4][6] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/7.xpm", &w, &h);
	img[4][7] = mlx_xpm_file_to_image(data->mlx, "sprite/P/I/8.xpm", &w, &h);
	img[4][8] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/1.xpm", &w, &h);
	img[4][9] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/2.xpm", &w, &h);
	img[4][10] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/3.xpm", &w, &h);
	img[4][11] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/4.xpm", &w, &h);
	img[4][12] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/5.xpm", &w, &h);
	img[4][13] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/6.xpm", &w, &h);
	img[4][14] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/7.xpm", &w, &h);
	img[4][15] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/8.xpm", &w, &h);
	img[4][16] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/9.xpm", &w, &h);
	img[4][17] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/10.xpm", &w, &h);
	img[4][18] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/11.xpm", &w, &h);
	img[4][19] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/12.xpm", &w, &h);
	img[4][20] = mlx_xpm_file_to_image(data->mlx, "sprite/P/A/13.xpm", &w, &h);
}

void	init_enemy_sprite_imgs(void ***img, t_data *data, int w, int h)
{
	img[5][0] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/0.xpm", &w, &h);
	img[5][1] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/1.xpm", &w, &h);
	img[5][2] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/2.xpm", &w, &h);
	img[5][3] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/3.xpm", &w, &h);
	img[5][4] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/4.xpm", &w, &h);
	img[5][5] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/5.xpm", &w, &h);
	img[5][6] = mlx_xpm_file_to_image(data->mlx, "sprite/G/I/6.xpm", &w, &h);
	img[5][7] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/1.xpm", &w, &h);
	img[5][8] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/2.xpm", &w, &h);
	img[5][9] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/3.xpm", &w, &h);
	img[5][10] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/4.xpm", &w, &h);
	img[5][11] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/5.xpm", &w, &h);
	img[5][12] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/6.xpm", &w, &h);
	img[5][13] = mlx_xpm_file_to_image(data->mlx, "sprite/G/V/7.xpm", &w, &h);
}

void	images_value(char *map, t_data *d, int w, int h)
{
	int	i;

	i = 0;
	d->img = (void ***) malloc (6 * sizeof (void **));
	if (!d->img)
		free_previous(d, map, 3);
	while (i < 4)
	{
		d->img[i] = (void **) malloc (1 * sizeof (void *));
		if (!d->img[i++])
			free_previous(d, map, 4);
	}
	d->img[i] = (void **) malloc (21 * sizeof (void *));
	if (!d->img[i++])
		free_previous(d, map, 4);
	d->img[i] = (void **) malloc (14 * sizeof (void *));
	if (!d->img[i++])
		free_previous(d, map, 4);
	init_basic_blocks(d->img, d, w, h);
	init_player_sprite_imgs(d->img, d, w, h);
	init_enemy_sprite_imgs(d->img, d, w, h);
}
