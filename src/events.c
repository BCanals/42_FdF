/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:46:03 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/16 16:31:16 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_close(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	return(0);
}

int hook(int keycode, t_all_data *all)
{
	ft_printf("keycode: %i\n", keycode);
	if (keycode == 65361)
		all->pos->x--;
	else if (keycode == 65363)
		all->pos->x++;
	else if (keycode == 65364)
		all->pos->y++;
	else if (keycode == 65362)
		all->pos->y--;
	else if (keycode == 65307)
		my_close(all->vars);
	return (0);
}
