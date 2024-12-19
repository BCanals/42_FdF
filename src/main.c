//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/19 15:00:46 by bcanals-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_prog *prog)
{
		
}

void	render_next_frame(void *void_prog)
{
	uint32_t	color;
	t_prog 		*prog;
	

	prog = void_prog;
	color = 0xFF00FFFF;
	ft_bzero(prog->img->pixels, prog->img->width * prog->img->height * sizeof(int32_t));
	mlx_image_to_window(prog->mlx, prog->img, 0, 0);
	//getchar();
	return ;
}


int	main(void)
{
	t_prog	prog;
	t_xy	*start;
	t_xy	*end;

	end = get_xy(100, 100, NULL);
	start = get_xy(200, 150, start);
	prog.2d_net = start;
	prog.mlx = mlx_init(700, 700, "bcanals- fdf", true);
	prog.pos = get_pos(100, 100);
	prog.img = mlx_new_image(prog.mlx, 700, 700);
	mlx_image_to_window(prog.mlx, prog.img, 0,0);
	// ft_printf("address in main: %p\n", all);
	mlx_key_hook(prog.mlx, hook, &prog);
	mlx_loop_hook(prog.mlx, *render_next_frame, &prog);
	mlx_loop(prog.mlx);
	mlx_terminate(prog.mlx);
}
