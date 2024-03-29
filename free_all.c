/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 09:57:16 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 14:29:20 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	destroy_all_imgs(t_data *d, void ***img)
{
	int	i;

	i = 0;
	while (i <= 3)
		mlx_destroy_image(d->mlx, img[i++][0]);
	i = 0;
	while (i <= 20)
		mlx_destroy_image(d->mlx, img[4][i++]);
	i = 0;
	while (i <= 13)
		mlx_destroy_image(d->mlx, img[5][i++]);
	i = 0;
	while (i < 6)
		free(d->img[i++]);
	free(d->img);
}

void	free_two_d_array(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

int	check_for_enemies(char **map, int flag)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'G' && flag == 0)
				return (1);
			if (map[i][j] == 'J' && flag == 1)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_enemy_status(t_data *d)
{
	int	i;

	i = 0;
	while (i < enemy_count(d->map))
	{
		if (d->enemy_status[i] == -1)
			return (1);
		i++;
	}
	return (0);
}

void	free_all(t_data *d, int flag)
{
	mlx_clear_window(d->mlx, d->mlx_window);
	destroy_all_imgs(d, d->img);
	if (check_for_enemies(d->map, 0) && flag >= 1)
	{
		free(d->to_free_in_the_end.i_add);
		if (flag > 1)
			free(d->to_free_in_the_end.j_add);
		if (flag > 3)
			free(d->to_free_in_the_end.r_l_add[0]);
		if (flag > 4)
			free(d->to_free_in_the_end.r_l_add[1]);
		if (flag > 2)
			free(d->to_free_in_the_end.r_l_add);
	}
	if (check_for_enemies(d->map, 1) || flag > 5 || check_enemy_status(d))
		free(d->to_free_in_the_end.k_add);
	free(d->enemy_status);
	free_two_d_array(d->map);
	system("leaks so_long");
	exit(0);
}
