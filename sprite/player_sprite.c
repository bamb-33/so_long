/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_sprite.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 15:59:06 by naadou            #+#    #+#             */
/*   Updated: 2024/01/29 22:24:56 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	enemy_detection(t_data *d)
{
	int	*p;

	p = starting_position(d->map);
	if (!p)
		free_all(d, 4);
	if (d->map[p[0]][p[1] + 1] == 'G')
		d->enemy_status[get_enemy_index(d->map, p[1] + 1, p[0])] = -1;
	if (d->map[p[0]][p[1] - 1] == 'G')
		d->enemy_status[get_enemy_index(d->map, p[1] - 1, p[0])] = -1;
	if (d->map[p[0] - 1][p[1]] == 'G')
		d->enemy_status[get_enemy_index(d->map, p[1], p[0] - 1)] = -1;
	if (d->map[p[0] + 1][p[1]] == 'G')
		d->enemy_status[get_enemy_index(d->map, p[1], p[0] + 1)] = -1;
	free(p);
}

void	player_sprites(void ***img, t_data *d, int w, int h)
{
	static int	i;
	static int	j;
	int			img_i;

	if (d->player_status == -1)
	{
		img_i = (j / 10) + 8;
		enemy_detection(d);
		if (j == 129)
		{
			d->player_status = 1;
			j = -1;
			i = 0;
		}
		mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][img_i], w, h);
		j++;
		return ;
	}
	img_i = (i / 25);
	if (i == 199)
		i = -1;
	mlx_put_image_to_window(d->mlx, d->mlx_window, img[4][img_i], w, h);
	i++;
}
