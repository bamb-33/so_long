/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:11:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/31 10:06:53 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	up(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0] - 1][p[1]] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free_all(data, 5);
	}
	if (data->map[p[0] - 1][p[1]] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free_all(data, 5);
	}
	if (data->map[p[0] - 1][p[1]] != '1' && data->map[p[0] - 1][p[1]] != 'E')
	{
		data->map[p[0] - 1][p[1]] = 'P';
		data->map[p[0]][p[1]] = '0';
		data->mov_counter++;
	}
}

void	down(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0] + 1][p[1]] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free_all(data, 5);
	}
	if (data->map[p[0] + 1][p[1]] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free_all(data, 5);
	}
	if (data->map[p[0] + 1][p[1]] != '1' && data->map[p[0] + 1][p[1]] != 'E')
	{
		data->map[p[0] + 1][p[1]] = 'P';
		data->map[p[0]][p[1]] = '0';
		data->mov_counter++;
	}
}

void	right(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0]][p[1] + 1] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free_all(data, 5);
	}
	if (data->map[p[0]][p[1] + 1] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free_all(data, 5);
	}
	if (data->map[p[0]][p[1] + 1] != '1' && data->map[p[0]][p[1] + 1] != 'E')
	{
		data->map[p[0]][p[1] + 1] = 'P';
		data->map[p[0]][p[1]] = '0';
		data->mov_counter++;
	}
}

void	left(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0]][p[1] - 1] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free_all(data, 5);
	}
	if (data->map[p[0]][p[1] - 1] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free_all(data, 5);
	}
	if (data->map[p[0]][p[1] - 1] != '1' && data->map[p[0]][p[1] - 1] != 'E')
	{
		data->map[p[0]][p[1] - 1] = 'P';
		data->map[p[0]][p[1]] = '0';
		data->mov_counter++;
	}
}
