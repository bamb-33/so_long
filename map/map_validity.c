/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validity.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 09:26:44 by naadou            #+#    #+#             */
/*   Updated: 2024/01/29 21:45:39 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	free_nodes(t_node *head)
{
	int		i;
	t_node	*tmp;

	i = 0;
	while (head->previous)
		head = head->previous;
	while (head)
	{
		tmp = head;
		free(tmp->content);
		head = head->next;
		free(tmp);
	}
}

t_node	*free_useless_node(t_node *node, char **hm_map, char **map, int flag)
{
	t_node	*previous_node;

	if (flag == 1)
	{
		free_two_d_array(hm_map);
		free_two_d_array(map);
		exit(1);
	}
	previous_node = node->previous;
	free(node->content);
	free(node);
	return (previous_node);
}

t_node	*init(char **hm_map, char **map, int *p, t_node *node)
{
	int		i;
	t_node	*new_node;

	i = 0;
	new_node = (t_node *) malloc (sizeof(t_node));
	new_node->content = (int *) malloc (sizeof(int) * 6);
	hm_map[p[0]][p[1]] = '1';
	while (i < 4)
		new_node->content[i++] = 0;
	if (map[p[0] - 1][p[1]] != '1' && hm_map[p[0] - 1][p[1]] != '1')
		new_node->content[0] = 1;
	if (map[p[0] + 1][p[1]] != '1' && hm_map[p[0] + 1][p[1]] != '1')
		new_node->content[1] = 1;
	if (map[p[0]][p[1] - 1] != '1' && hm_map[p[0]][p[1] - 1] != '1')
		new_node->content[2] = 1;
	if (map[p[0]][p[1] + 1] != '1' && hm_map[p[0]][p[1] + 1] != '1')
		new_node->content[3] = 1;
	new_node->content[4] = p[0];
	new_node->content[5] = p[1];
	new_node->previous = node;
	new_node->next = NULL;
	if (node)
		node->next = new_node;
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
	t_node	*new_node;
	t_node	*node_sent;

	if (!p)
		free_useless_node(node, hm_map, map, 1);
	new_node = init(hm_map, map, p, node);
	node_sent = new_node;
	while (move(hm_map, map, p, node_sent) == 0)
	{
		if (node_sent->previous == NULL || path_check(hm_map))
		{
			free(p);
			free_two_d_array(map);
			free_nodes(node_sent);
			return ;
		}
		map[node_sent->content[4]][node_sent->content[5]] = '0';
		node_sent = free_useless_node(node_sent, hm_map, map, -1);
		map[node_sent->content[4]][node_sent->content[5]] = 'P';
		free(p);
		p = starting_position(map);
	}
	free(p);
	map_validity(hm_map, map, starting_position(map), node_sent);
}
