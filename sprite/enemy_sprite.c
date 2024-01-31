/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_sprite.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 16:31:59 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 20:32:56 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	enemy_obstacles(t_data *d, int i[], int *right, int *left)
{
	if ((d->map[i[0]][i[1] + 1] != '0' && d->map[i[0]][i[1] + 1] != 'P') && (d->map[i[0]][i[1] - 1] != '0' && d->map[i[0]][i[1] - 1] != 'P'))
	{
		*left = 0;
		*right = 0;
	}
	else if (d->map[i[0]][i[1] + 1] == '0' || d->map[i[0]][i[1] + 1] == 'P')
	{
		*left = 0;
		*right = 1;
	}
	else if (d->map[i[0]][i[1] - 1] == '0' || d->map[i[0]][i[1] - 1] == 'P')
	{
		*left = 1;
		*right = 0;
	}
}

void	enemy_movement(t_data *d, int i[], int right, int left)
{
	if (right == 1)
	{
		if (d->map[i[0]][i[1] + 1] == 'P')
		{
			ft_putstr_fd("YOU DIED LIL NIGGA\n", 1);
			free_all(d, 4);
		}
		d->map[i[0]][i[1]] = '0';
		d->map[i[0]][i[1] + 1] = 'G';
	}
	else if (left == 1)
	{
		if (d->map[i[0]][i[1] - 1] == 'P')
		{
			ft_putstr_fd("YOU DIED LIL NIGGA\n", 1);
			free_all(d, 4);
		}
		d->map[i[0]][i[1]] = '0';
		d->map[i[0]][i[1] - 1] = 'G';
	}
}

void	enemy_dying_sprite(t_data *d, void ***img, int w, int h)
{
	int			i;
	int			img_i;
	static int	*k;

	i = 0;
	if (!k)
	{
		k = (int *) malloc (sizeof(int) * enemy_count(d->map));
		if (!k)
			free_all(d, 5);
		while (i < enemy_count(d->map))
			k[i++] = 0;
		d->to_free_in_the_end.k_add = k;
	}
	i = get_enemy_index(d->map, w / 64, h / 64);
	img_i = (k[i] / 10) + 5;
	mlx_put_image_to_window(d->mlx, d->mlx_window, img[0][0], w, h);
	if (k[i] == 69)
	{
		d->map[h / 64][(w / 64)] = 'J';
		d->enemy_status[i] = 1;
		k[i] = -1;
	}
	mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][img_i], w, h);
	k[i]++;
}

void	allocation(int **i, int **j, int ***r_l, t_data *d)
{
	int	z;

	z = 0;
	*i = (int *) malloc (sizeof(int) * enemy_count(d->map));
	if (!(*i))
		free_all(d, -1);
	*j = (int *) malloc (sizeof(int) * enemy_count(d->map));
	if (!(*j))
		free_all(d, 1);
	*r_l = (int **) malloc (sizeof(int *) * 2);
	if (!(*r_l))
		free_all(d, 2);
	(*r_l)[0] = (int *) malloc (sizeof(int) * enemy_count(d->map));
	if (!(*r_l)[0])
		free_all(d, 3);
	(*r_l)[1] = (int *) malloc (sizeof(int) * enemy_count(d->map));
	if (!(*r_l)[1])
		free_all(d, 4);
	while (z < enemy_count(d->map))
	{
		(*i)[z] = 0;
		(*j)[z] = 0;
		(*r_l)[0][z++] = 1;
	}
	save_variables(d, *i, *j, *r_l);
}

void	enemy_sprites(void ***img, t_data *d, int w, int h)
{
	static int	*i;
	static int	*j;
	static int	**r_l;
	int			p;

	if (!i && !j && !r_l)
		allocation(&i, &j, &r_l, d);
	p = get_enemy_index(d->map, w / 64, h / 64);
	if (d->enemy_status[p] == -1)
	{
		enemy_dying_sprite(d, img, w, h);
		return ;
	}
	if (i[p] == 75)
	{
		enemy_obstacles(d, (int []){h / 64, w / 64}, &r_l[0][p], &r_l[1][p]);
		enemy_movement(d, (int []){h / 64, w / 64}, r_l[0][p], r_l[1][p]);
		i[p] = 0;
	}
	if (j[p] == 174)
		j[p] = -1;
	mlx_put_image_to_window(d->mlx, d->mlx_window, img[5][(j[p] / 25)], w, h);
	i[p]++;
	j[p]++;
}
