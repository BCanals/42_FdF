/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:46:03 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/29 23:08:24 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_close(t_prog *prog)
{
	mlx_terminate(prog->mlx);
	return(0);
}

void translate(t_prog *prog, int key)
{
	int		i;
	int 	step;
	t_xy	*x;
	t_xy	*y;

	y = prog->net_2d;
	step = 1 - key % 2 * 2;
	i = key >> 1;
	while (y)
	{
		x = y;
		while (x)
		{
			x->pos[i] += step;
			x = x->n_x;
		}
		y = y->n_y;
	}
}

void hook(mlx_key_data_t keycode, void *void_prog)
{
	t_prog	*prog;

	prog = void_prog;
	if (keycode.key > 261 && keycode.key < 266)
		translate(prog, keycode.key % 262);
	/*
	ft_printf("keycode: %i\n", keycode);
	if (keycode.key == MLX_KEY_LEFT)
		prog->net_2d->n_x->x--;
	if (keycode.key == MLX_KEY_RIGHT)
		prog->net_2d->n_x->x++;
	if (keycode.key == MLX_KEY_DOWN)
		prog->net_2d->n_x->y++;
	if (keycode.key == MLX_KEY_UP)
		prog->net_2d->n_x->y--;
	 */
	if (keycode.key == MLX_KEY_ESCAPE)
		my_close(prog);
	prog->update = true;
}
