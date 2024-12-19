/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2d_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 11:51:23 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/19 12:08:18 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_xy	*get_xy(int x, int y, t_xy *next_x)
{
	t_xy	*rtrn;

	rtrn = malloc(sizeof(t_xy));
	if (!rtrn)
		return (NULL);
	rtrn->x = x;
	rtrn->y = y;
	rtrn->n_x = next_x;
	rtrn->n_y = NULL;
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
