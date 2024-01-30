/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 09:31:40 by naadou            #+#    #+#             */
/*   Updated: 2024/01/30 17:38:33 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	two_in_one(t_node *node, char **hm_map, char **map)
{
	free_nodes(node);
	free_useless_node(node, hm_map, map, 1);
}

void	check_for_exits(char **map, char **hm_map, int *p)
{
	if (map[p[0] - 1][p[1]] == 'E')
		hm_map[p[0] - 1][p[1]] = '1';
	if (map[p[0] + 1][p[1]] == 'E')
		hm_map[p[0] + 1][p[1]] = '1';
	if (map[p[0]][p[1] - 1] == 'E')
		hm_map[p[0]][p[1] - 1] = '1';
	if (map[p[0]][p[1] + 1] == 'E')
		hm_map[p[0]][p[1] + 1] = '1';
}

int	valid_rout(t_node *node, char **map, char **hm_map, int *p)
{
	if (map[p[0] - 1][p[1]] != 'E'
		&& map[p[0] - 1][p[1]] != '1' && hm_map[p[0] - 1][p[1]] != '1')
		node->content[0] = 1;
	if (map[p[0] + 1][p[1]] != 'E'
		&& map[p[0] + 1][p[1]] != '1' && hm_map[p[0] + 1][p[1]] != '1')
		node->content[1] = 1;
	if (map[p[0]][p[1] - 1] != 'E'
		&& map[p[0]][p[1] - 1] != '1' && hm_map[p[0]][p[1] - 1] != '1')
		node->content[2] = 1;
	if (map[p[0]][p[1] + 1] != 'E'
		&& map[p[0]][p[1] + 1] != '1' && hm_map[p[0]][p[1] + 1] != '1')
		node->content[3] = 1;
	check_for_exits(map, hm_map, p);
	return (0);
}