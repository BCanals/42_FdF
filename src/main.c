//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2024/12/20 19:08:49 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_prog *prog, uint32_t color)
{
	t_xy	*ini;
	t_xy	*end;
	int		dx;
	int		dy;
	int		D;
	int		x;
	int		y;

	ini = prog->net_2d;
	end = ini->n_x;
	dx = end->x - ini->x;
	dy = end->y - ini->y;
	D = 2 * dy - dx;
	x = ini->x;
	y = ini->y;
	//printf("start x = %i,  end X = %i", ini->x, end->x);
	while (x <= end->x)
	{
		my_mlx_pixel_put(prog->img, x, y, color);
		//put_circle(prog->img, get_xy(x, y, NULL), 5, color);
		if (D > 0)
		{
			y++;
			D -= 2 * dx;
		}
		D += 2 * dy;
		x++;
	}
	//getchar();
}

void	render_next_frame(void *void_prog)
{
	uint32_t	color;
	t_prog 		*prog;
	

	prog = void_prog;
	color = 0xFF00FFFF;
	ft_bzero(prog->img->pixels, prog->img->width * prog->img->height * sizeof(int32_t));
	//put_circle(prog->img, get_xy(350, 350, NULL), 50, 0xFF00FFFF);
	draw_line(prog, color);
	mlx_image_to_window(prog->mlx, prog->img, 0, 0);
	//getchar();
	return ;
}


int	main(void)
{
	t_prog	prog;
	t_xy	*start;
	t_xy	*end;

	end = get_xy(500, 100, NULL);
	start = get_xy(200, 200, end);
	prog.net_2d = start;
	prog.mlx = mlx_init(700, 700, "bcanals- fdf", true);
	prog.img = mlx_new_image(prog.mlx, 700, 700);
	mlx_image_to_window(prog.mlx, prog.img, 0,0);
	// ft_printf("address in main: %p\n", all);
	mlx_key_hook(prog.mlx, hook, &prog);
	mlx_loop_hook(prog.mlx, *render_next_frame, &prog);
	mlx_loop(prog.mlx);
	mlx_terminate(prog.mlx);
}
