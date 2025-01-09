//* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcanals- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/14 18:05:01 by bcanals-          #+#    #+#             */
/*   Updated: 2025/01/09 18:52:46 by bizcru           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	abs(int i)
{
	if (i >= 0)
		return (i);
	return (-i);
}

void	draw_line(t_xy *ini, t_xy *end, uint32_t color, mlx_image_t *img)
{
	int		dx;
	int		dy;
	int		sx;
	int		sy;
	int		x;
	int		y;
	int		error;
	int		e2;
	
	if (!ini || !end)
		return ;
	dx = abs(end->x - ini->x);
	dy = 0 - abs(end->y - ini->y);
	//printf("dx = %i, dy = %i\n", dx, dy);
	x = ini->x;
	y = ini->y;
	sx = 1;
	sy = 1;
	error = dx + dy;
	//printf("error: %i\n", error);
	if (x >= end->x)
		sx = sx * -1;
	if (y >= end->y)
		sy = sy * -1;

	//printf("start x = %i,  end X = %i", ini->x, end->x);
	while (1)
	{
		//printf("printing %i, %i\n", x, y);
		my_mlx_pixel_put(img, x, y, color);
		//put_circle(prog->img, get_xy(x, y, NULL), 5, color);
		if (x == end->x && y == end->y)
			break ;
		e2 = 2 * error;
		//printf("e2 = %i\n", e2);
		//getchar();
		if (e2 >= dy)
		{
			error += dy;
			//printf("error = %i\n", error);
			//getchar();
			x += sx;
			//printf("x = %i\n", x);
			//getchar();
		}
		if (e2 <= dx)
		{
			error += dx;
			//printf("error = %i\n", error);
			//getchar();
			y += sy;
			//printf("y = %i\n", y);
			//getchar();
		}
	}
	//getchar();
}


void	render_next_frame(void *void_prog)
{
	uint32_t	color;
	t_prog 		*prog;
	t_xy		*ini;
	t_xy		*paint;
	
	prog = void_prog;
	color = 0xFF00FFFF;
	if (prog->update == true)
	{
		ft_bzero(prog->img->pixels, prog->img->width * prog->img->height * sizeof(int32_t));
		ini = prog->net_2d;
		while (ini)
		{
			paint = ini;
			while (paint)
			{	//put_circle(prog->img, get_xy(350, 350, NULL), 50, 0xFF00FFFF);
				draw_line(paint, paint->n_x, color, prog->img);
				draw_line(paint, paint->n_y, color, prog->img);
				paint = paint->n_x;
			}
			ini = ini->n_y;
		}
		mlx_image_to_window(prog->mlx, prog->img, 0, 0);
		//getchar();
		prog->update = false;
	}
	return ;
}

// TO-DO: in general, see if it makes sense to set a more specific int type such as int32_t

int	main(int argc, char **argv)
{
	t_prog	prog;
	/*
	t_xy	*start;
	t_xy	*end;
	t_xy	*mid;
	t_xy	*starty;
	t_xy	*midy;
	t_xy	*endy;

	endy = get_xy(300, 250, NULL, NULL);
	midy = get_xy(250, 250, endy, NULL);
	starty = get_xy(200, 250, midy, NULL);
	end = get_xy(300, 200, NULL, endy);
	mid = get_xy(250, 200, end, midy);
	start = get_xy(200, 200, mid, starty);
	prog.net_2d = start;
	*/
	if (argc != 2)
	{
		ft_printf("Usage: ./fdf file_path\n");
		return (0);
	}
	if (load_map(&prog, argv[1]) == -1)
		return 0;
	prog.mlx = mlx_init(700, 700, "bcanals- fdf", true);
	prog.img = mlx_new_image(prog.mlx, 700, 700);
	prog.update = true;
	mlx_image_to_window(prog.mlx, prog.img, 0,0);
	// ft_printf("address in main: %p\n", all);
	mlx_key_hook(prog.mlx, hook, &prog);
	mlx_loop_hook(prog.mlx, *render_next_frame, &prog);
	mlx_loop(prog.mlx);
	mlx_terminate(prog.mlx);
}
