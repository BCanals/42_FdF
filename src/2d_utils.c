/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:51:23 by bcanals-          #+#    #+#             */
/*   Updated: 2025/01/03 12:08:47 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xy	*get_xy(int x, int y, t_xy *next_x, t_xy *next_y)
{
	t_xy	*rtrn;

	rtrn = malloc(sizeof(t_xy));
	if (!rtrn)
		return (NULL);
	rtrn->x = x;
	rtrn->y = y;
	rtrn->n_x = next_x;
	rtrn->n_y = next_y;
	return (rtrn);
}

t_xyz *get_xyz(int x, int y, int z, t_xyz *next_x)
{
	t_xyz *rtrn;

	rtrn = malloc(sizeof(t_xyz));
	if (!rtrn)
		return (NULL);
	rtrn->x = x;
	rtrn->y = y;
	rtrn->z = z;
	rtrn->n_x = next_x;
	rtrn->n_y = NULL;
	return (rtrn);
}
