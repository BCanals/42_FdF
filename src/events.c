/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 21:46:03 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/19 22:04:23 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int my_close(t_prog *prog)
{
	mlx_terminate(prog->mlx);
	return(0);
}

void hook(mlx_key_data_t keycode, void *void_prog)
{
	t_prog	*prog;

	prog = void_prog;
	//.ft_printf("keycode: %i\n", keycode);
	/*if (keycode.key == MLX_KEY_LEFT)
		prog->pos->x--;
	else if (keycode.key == MLX_KEY_RIGHT)
		prog->pos->x++;
	else if (keycode.key == MLX_KEY_DOWN)
		prog->pos->y++;
	else if (keycode.key == MLX_KEY_UP)
		prog->pos->y--;*/
	if (keycode.key == MLX_KEY_ESCAPE)
		my_close(prog);
}
