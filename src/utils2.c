/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 16:16:48 by bcanals-          #+#    #+#             */
/*   Updated: 2025/01/10 17:34:53 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	load_c(int c[2], int size)
{
	c[0] = size;
	c[1] += 1;
}

int	split_count(char **split)
{
	int	i;

	i = 0;
	while (split[i])
		i++;
	return (i);
}

int	points_clean_up(t_xyz *start)
{
	t_xyz	*next_line;
	t_xyz	*next;

	next_line = start->n_y;
	while (start)
	{
		while (start)
		{
			next = start->n_x;
			free(start);
			start = next;
		}
		start = next_line;
		if (next_line)
			next_line = next_line->n_y;
	}
	return (0);
}

void	update_limits(t_xyz *p, t_limits *l)
{
	if (p->proj_x < l->min_x)
		l->min_x = p->proj_x;
	if (p->proj_x > l->max_x)
		l->max_x = p->proj_x;
	if (p->proj_y < l->min_y)
		l->min_y = p->proj_y;
	if (p->proj_y > l->max_y)
		l->max_y = p->proj_y;
}
