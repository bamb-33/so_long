/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 12:34:27 by naadou            #+#    #+#             */
/*   Updated: 2023/12/12 15:11:54 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	so_long(int fd)
{
	int	i;
	char *str_map[];
	while (1)
	{
		str_map[i] = get_nextline(fd);
	}
}