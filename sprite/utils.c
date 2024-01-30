/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: naadou <naadou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 22:25:31 by naadou            #+#    #+#             */
/*   Updated: 2024/01/30 13:12:44 by naadou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header.h"

void	save_variables(t_data *d, int *i, int *j, int **r_l)
{
	d->to_free_in_the_end.i_add = i;
	d->to_free_in_the_end.j_add = j;
	d->to_free_in_the_end.r_l_add = r_l;
}
