/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 17:11:34 by naadou            #+#    #+#             */
/*   Updated: 2024/01/29 16:32:12 by naadou           ###   ########.fr       */
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
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0] - 1][p[1]] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0] - 1][p[1]] != '1' && data->map[p[0] - 1][p[1]] != 'E')
	{
		data->map[p[0] - 1][p[1]] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	free(p);
}

void	down(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0] + 1][p[1]] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0] + 1][p[1]] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0] + 1][p[1]] != '1' && data->map[p[0] + 1][p[1]] != 'E')
	{
		data->map[p[0] + 1][p[1]] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	free(p);
}

void	right(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0]][p[1] + 1] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0]][p[1] + 1] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0]][p[1] + 1] != '1' && data->map[p[0]][p[1] + 1] != 'E')
	{
		data->map[p[0]][p[1] + 1] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	free(p);
}

void	left(t_data *data)
{
	int	*p;

	p = starting_position(data->map);
	if (data->map[p[0]][p[1] - 1] == 'E' && collectibles_check(data) == 1)
	{
		printf("YOU WON!!!!");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0]][p[1] - 1] == 'G')
	{
		printf("YOU DIED LIL NIGGA\n");
		free(p);
		free_all(data);
		exit(0);
	}
	if (data->map[p[0]][p[1] - 1] != '1' && data->map[p[0]][p[1] - 1] != 'E')
	{
		data->map[p[0]][p[1] - 1] = 'P';
		data->map[p[0]][p[1]] = '0';
	}
	free(p);
}
