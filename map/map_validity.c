/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:26:44 by naadou            #+#    #+#             */
/*   Updated: 2024/01/28 19:16:34 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

t_node	init(char **hm_map, char **map, int *p, t_node *node)
{
	int		i;
	t_node	new_node;

	i = 0;
	new_node.content = (int *) malloc (sizeof(int) * 6);
	hm_map[p[0]][p[1]] = '1';
	while (i < 4)
		new_node.content[i++] = 0;
	if (map[p[0] - 1][p[1]] != '1' && hm_map[p[0] - 1][p[1]] != '1')
		new_node.content[0] = 1;
	if (map[p[0] + 1][p[1]] != '1' && hm_map[p[0] + 1][p[1]] != '1')
		new_node.content[1] = 1;
	if (map[p[0]][p[1] - 1] != '1' && hm_map[p[0]][p[1] - 1] != '1')
		new_node.content[2] = 1;
	if (map[p[0]][p[1] + 1] != '1' && hm_map[p[0]][p[1] + 1] != '1')
		new_node.content[3] = 1;
	new_node.content[4] = p[0];
	new_node.content[5] = p[1];
	new_node.previous = node;
	if (node)
		node->next = &new_node;
	return (new_node);
}

int	move(char **hm_map, char **map, int *p, t_node *node)
{
	if (node->content[0] == 1 && hm_map[p[0] - 1][p[1]] != '1')
	{
		map[p[0] - 1][p[1]] = 'P';
		node->content[0] = 0;
	}
	else if (node->content[1] == 1 && hm_map[p[0] + 1][p[1]] != '1')
	{
		map[p[0] + 1][p[1]] = 'P';
		node->content[1] = 0;
	}
	else if (node->content[2] == 1 && hm_map[p[0]][p[1] - 1] != '1')
	{
		map[p[0]][p[1] - 1] = 'P';
		node->content[2] = 0;
	}
	else if (node->content[3] == 1 && hm_map[p[0]][p[1] + 1] != '1')
	{
		map[p[0]][p[1] + 1] = 'P';
		node->content[3] = 0;
	}
	else
		return (0);
	map[p[0]][p[1]] = '0';
	return (1);
}

void	map_validity(char **hm_map, char **map, int *p, t_node *node)
{
	t_node	new_node;
	t_node	*node_sent;

	new_node = init(hm_map, map, p, node);
	node_sent = &new_node;
	while (move(hm_map, map, p, node_sent) == 0)
	{
		if (node_sent->previous == NULL)
		{
			return ;
		}
		map[node_sent->content[4]][node_sent->content[5]] = '0';
		node_sent = node_sent->previous;
		map[node_sent->content[4]][node_sent->content[5]] = 'P';
		p = starting_position(map);
	}
	map_validity(hm_map, map, starting_position(map), node_sent);
}
